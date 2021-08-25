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
    if (EExterno(*no) || position < (*no)->No.NoInterno.index){//Cria um novo no externo
        aux = CriaNoExt(chave);
        char letter = letraPosition(position,&chave);
        if (Bit(position,chave) == 1)
            return (CriaNoInt(letter,position,no,&aux));
        else return (CriaNoInt(letter,position,&aux,no));
    }
    else{
        if (Bit((*no)->No.NoInterno.index,chave) == 1){ //&& (letraPosition((*no)->No.NoInterno.index,&chave) > (*no)->No.NoInterno.letter)
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
            if(Bit(aux->No.NoInterno.index,chave) == 1) aux = aux->No.NoInterno.direita;
            else aux = aux->No.NoInterno.esquerda;
            //acha o primeiro bit diferente
        }
        i = 1;
        while ((i<=chave.tamanho)&(Bit((int)i,chave) == Bit((int)i,aux->No.chave)))
            i++;
        if (i > chave.tamanho){
            putIndex(&aux->No.chave.index,&chave.palavraIndex);
            return *no;
        }
        else{
            putIndex(&chave.index,&aux->No.chave.palavraIndex);
            return (InsereEntre(chave,no, i));
        }
    }
}

TipoAuxiliar Bit(TipoIndexAmp position,TipoChave chave){
    // Retorna o i-esimo bit da chave k a partir da esquerda
    int aux;
    if (position == 0){
        return 0;
    }
    else{
        aux = letraReturn(position,&chave);
        for (int j = 1;j <= chave.tamanho - position;j++){
            aux /= 2;
        }
        return (aux & 1);
    }
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
    aux->No.NoInterno.index = position;
    aux->No.NoInterno.letter = letter;
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
    if (Bit(no->No.NoInterno.index,chave) == 0)
        search(chave,no->No.NoInterno.esquerda);
    else search(chave,no->No.NoInterno.direita);
}

void imprimeArvore(treePatricia *no){
    if(no->tipo == externo){
        imprimeWord(&no->No.chave);
    }
    else{
        imprimeArvore(no->No.NoInterno.esquerda);
        imprimeArvore(no->No.NoInterno.direita);
    }
}