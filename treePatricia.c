//
// Created by pedro on 18/08/2021.
//

#include "treePatricia.h"

void iniciaPatricia(TypeTree *noRaiz){
    *noRaiz = NULL;
}
void wordOnPatricia(treePatricia **no,TipoChave chave){
    *no = Insere(chave,no);
}

TypeTree InsereEntre(TipoChave chave,TypeTree *no,int position,char letraNointerno){
    TypeTree aux;
    if (EExterno(*no)){//Cria um novo no externo
        aux = CriaNoExt(chave);
        if (Relacao(Caractere(position, chave), Caractere(position,(*no)->No.chave)))
            return (CriaNoInt(letraNointerno,position,no,&aux));
        else return (CriaNoInt(letraNointerno,position,&aux,no));
    }
    else if(position < (*no)->No.NoInterno.index.position){
        aux = CriaNoExt(chave);
        if(Relacao(Caractere(position,chave),letraNointerno)){
            return (CriaNoInt(letraNointerno,position,no,&aux));
        }
        else{
            return (CriaNoInt(letraNointerno,position,&aux,no));
        }
    }
    else{//Inserimos quando o caractere for maior ou igual a direita e menor a esquerda
        if (Relacao(Caractere((*no)->No.NoInterno.index.position, chave), (*no)->No.NoInterno.index.letra)){
            (*no)->No.NoInterno.direita = InsereEntre(chave,&(*no)->No.NoInterno.direita,position,letraNointerno);
        }
        else{
            (*no)->No.NoInterno.esquerda = InsereEntre(chave,&(*no)->No.NoInterno.esquerda,position,letraNointerno);
        }
    }
    return (*no);
}


TypeTree Insere(TipoChave chave,TypeTree *no){
    TypeTree aux;
    int i;
    char letra;
    char letraDifere;
    if(*no == NULL){
        putIndex(&chave.index,&chave.palavraIndex);
        return (CriaNoExt(chave));
    }
    else{
        aux = *no;
        while (!EExterno(aux)){
            if((*no)->No.NoInterno.index.position > chave.tamanho){
                letra = Caractere(chave.tamanho,chave);
            }
            else{
                letra = Caractere(aux->No.NoInterno.index.position,chave);
            }


            if(Relacao(letra, aux->No.NoInterno.index.letra))
                aux = aux->No.NoInterno.direita;
            else aux = aux->No.NoInterno.esquerda;
            //acha o primeiro bit diferente
        }

        if(wordCompare(&chave,&aux->No.chave) == 0){
            putIndex(&aux->No.chave.index,&chave.palavraIndex);
            return *no;
        }

        i = 1;
        while (Caractere(i,chave) == Caractere(i,aux->No.chave))
            i++;
//
        if(Caractere(i,chave) >= Caractere(i,aux->No.chave)){
            letraDifere = Caractere(i,chave);
        }
        else{
            letraDifere = Caractere(i,aux->No.chave);
        }
        putIndex(&chave.index,&chave.palavraIndex);
        return InsereEntre(chave,no,i,letraDifere);
    }
}

char Caractere(int i,TipoChave chave){
    i--;
    return (letraPosition(i,&chave));
}
int Relacao(char a, char b){
    return a >= b;
}

int EExterno(TypeTree no){
    return (no->tipo == externo);
}

TypeTree CriaNoInt(char letter,int position,TypeTree *Esquerda,TypeTree *Direita){
    TypeTree aux;
    aux = (TypeTree) malloc(sizeof(treePatricia));
    aux->tipo = interno;
    aux->No.NoInterno.esquerda = *Esquerda;
    aux->No.NoInterno.direita = *Direita;
    aux->No.NoInterno.index.position = position;
    aux->No.NoInterno.index.letra = letter;
    return aux;
}
TypeTree CriaNoExt(TipoChave chave){
    TypeTree aux;
    aux = (TypeTree) malloc(sizeof(treePatricia));
    aux->tipo = externo;
    aux->No.chave = chave;
    return aux;
}

void busca(char *termoBusca, TypeTree no,int qtdDocumento,char nomeBase[20],int *idDocs){
    TipoChave chaves[strlen(termoBusca)/2];
    int position = 0;
    for(int i = 0;i< strlen(termoBusca);i++){
        Word termo;
        iniciaWord(&termo);
        while (termoBusca[i] != ' ' && i< strlen(termoBusca)){
            insereLetra(&termo,termoBusca[i]);
            i++;
        }
        chaves[position] = termo;
        position++;
    }
    relevance *relevance1 = ponderation(no,qtdDocumento,chaves,position,nomeBase,idDocs);
    insercaoOrdena(relevance1,qtdDocumento);
    for(int j = 0;j<qtdDocumento;j++){
        printf("Arquivo:%s Identificador:%d\n",relevance1[j].nomeDoc,relevance1[j].idDoc);
    }
}

void insercaoOrdena(relevance *relevancias,int tamanho){
    int j ;
    for (int i = 1; i < tamanho; i++)
    {
        relevance aux = relevancias[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( aux.relevancia > relevancias[j].relevancia ) )
        {
            relevancias[j + 1] = relevancias[j];
            j--;
        }
        relevancias[j + 1] = aux;
    }
}

double peso(int numeroOcorrencias,int qtdDocContem,int qtdDocumento){
    double resultado = numeroOcorrencias *(log(qtdDocumento)/qtdDocContem);//depois conferir sobre o valor do log
    return resultado;
}

relevance *ponderation(TypeTree no,int qtdDocumento,TipoChave *termos,int qtdTermosBusca,char nomeBase[20],int *idDocs){
    relevance *relevancias = (relevance*)malloc(qtdDocumento * sizeof (relevance));
    for(int i = 0;i<qtdDocumento;i++){
        relevancias[i].relevancia = relevancia(no,termos,qtdTermosBusca,idDocs[i],qtdDocumento);
        strcpy(relevancias[i].nomeDoc,nomeBase);
        relevancias[i].idDoc = idDocs[i];
        strcat(relevancias[i].nomeDoc,".txt");
    }
    return relevancias;
}

void qtdTermos(TypeTree no,int idDoc, int *quantidadeInitEnd){
    if(EExterno(no)){
        if(idDocBe(&no->No.chave.index,idDoc)){
            quantidadeInitEnd[0]++;
        }
    }
    else{
        qtdTermos(no->No.NoInterno.esquerda, idDoc, quantidadeInitEnd);
        qtdTermos(no->No.NoInterno.direita, idDoc, quantidadeInitEnd);
    }
}

double relevancia(TypeTree no,TipoChave *termos,int qtdTermosBusca,int idDoc,int qtdDocumentos){
    double pesos = 0;
    int termosDistintos = 0;
    qtdTermos(no,idDoc,&termosDistintos);
    for (int j = 0;j<qtdTermosBusca;j++){
        TipoChave *buscaTermo = search(termos[j],no);
        int numeroOcorre = numeroOcorrencias(&buscaTermo->index,idDoc);
        int numeroDocContem = buscaTermo->index.tamanho;
        pesos += peso(numeroOcorre,numeroDocContem,qtdDocumentos);
    }
    return (1/((double )termosDistintos))*pesos;
}

TipoChave* search(TipoChave chave,TypeTree no){
    TipoChave chaveVazia;
    iniciaWord(&chaveVazia);
    if (EExterno(no)){
        if (wordCompare(&chave,&no->No.chave) == 0){
            return &no->No.chave;
        }
        else{
            return &chaveVazia;
        }
    }
    if (Relacao(Caractere(no->No.NoInterno.index.position, chave), no->No.NoInterno.index.letra))
        search(chave,no->No.NoInterno.direita);
    else search(chave,no->No.NoInterno.esquerda);
}

void imprimeArvore(treePatricia *no){
    if(EExterno(no)){
        imprimeWord(&no->No.chave);
    }
    else{
        imprimeArvore(no->No.NoInterno.esquerda);
        imprimeArvore(no->No.NoInterno.direita);
    }
}