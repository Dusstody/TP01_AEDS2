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

TypeTree InsereEntre(TipoChave chave,TypeTree *no,int position){
    TypeTree aux;
    char caractere;
    if (EExterno(*no) || position < (*no)->No.NoInterno.index.position){//Cria um novo no externo

        if(EExterno(*no)){
            caractere = Caractere((short)position,(*no)->No.chave);
        }
        else{
            caractere = (*no)->No.NoInterno.index.letra;
        }

        aux = CriaNoExt(chave);
        char letter = Caractere((short)position,chave);
        if (MaiorIgual(Caractere((short) position, chave), caractere))
            return (CriaNoInt(letter,position,no,&aux));
        else return (CriaNoInt(caractere,position,&aux,no));
    }
    else{
        if (MaiorIgual(Caractere((*no)->No.NoInterno.index.position, chave), (*no)->No.NoInterno.index.letra)){
            (*no)->No.NoInterno.direita = InsereEntre(chave,&(*no)->No.NoInterno.direita,position);
        }
        else{
            (*no)->No.NoInterno.esquerda = InsereEntre(chave,&(*no)->No.NoInterno.esquerda,position);
        }
        return (*no);
    }
}


TypeTree Insere(TipoChave chave,TypeTree *no){
    TypeTree aux;
    int i;
    if(*no == NULL){
        putIndex(&chave.index,&chave.palavraIndex);
        return (CriaNoExt(chave));
    }
    else{
        aux = *no;
        while (!EExterno(aux)){
            if(MaiorIgual(Caractere(aux->No.NoInterno.index.position, chave), aux->No.NoInterno.index.letra))
                aux = aux->No.NoInterno.direita;
            else aux = aux->No.NoInterno.esquerda;
            //acha o primeiro bit diferente
        }
        i = 0;

        if(chave.tamanho > aux->No.chave.tamanho){

            while ((i<=chave.tamanho) && (Caractere((short)i,chave) == Caractere((short)i,aux->No.chave)))
                i++;

            if(i >= chave.tamanho){
                putIndex(&aux->No.chave.index, &chave.palavraIndex);
                return *no;
            }
            else{
                putIndex(&chave.index,&chave.palavraIndex);
                return (InsereEntre(chave,no, i));
            }
        }

        else{
            while ((i <= aux->No.chave.tamanho) && (Caractere((short)i,chave) == Caractere((short)i,aux->No.chave)))
                i++;

            if(i >= aux->No.chave.tamanho){
                putIndex(&aux->No.chave.index, &chave.palavraIndex);
                return *no;
            }
            else{
                putIndex(&chave.index,&chave.palavraIndex);
                return (InsereEntre(chave,no, i));
            }
        }
    }
}

char Caractere(short i,TipoChave chave){
    return (letraPosition(i,&chave));
}
int MaiorIgual(char a, char b){
    return a >= b ? TRUE:FALSE;
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

void pesquisa(char *palavra,TypeTree no){
    TipoChave chave;
    iniciaWord(&chave);
    insereWord(&chave,palavra);
    return search(chave,no);
}
void search(TipoChave chave,TypeTree no){
    Word palavraVazia;
    iniciaWord(&palavraVazia);
    if (EExterno(no)){
        if (wordCompare(&chave,&no->No.chave) == 0){
            imprimeWord(&no->No.chave);
        }
        return;
    }
    if (MaiorIgual(Caractere(no->No.NoInterno.index.position, chave), no->No.NoInterno.index.letra))
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