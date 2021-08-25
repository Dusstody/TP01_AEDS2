//
// Created by pedro on 19/08/2021.
//

#include "IndexInverted.h"


void startIndex(invertedIndex *inverted){
    inverted->inicio = NULL;
    inverted->fim = inverted->inicio;
    inverted->tamanho = 0;
}
void putIndex(invertedIndex *inverted,indexPalavra *index){
    if(inverted->fim == NULL){
        inverted->fim = (PonteiroIndex) malloc(sizeof(indeces));
        inverted->inicio = inverted->fim;
        inverted->fim->inverted = *index;
        inverted->fim->prox = NULL;
        inverted->fim->anterior = NULL;
        inverted->tamanho++;
        return;
    }
    if(inverted->fim->anterior == NULL && (inverted->fim->inverted.idDoc != index->idDoc)){
        inverted->fim->anterior = inverted->fim;
        inverted->fim->prox = (PonteiroIndex) malloc(sizeof(indeces));
        inverted->fim = inverted->fim->prox;
        inverted->fim->inverted = *index;
        inverted->fim->prox = NULL;
        inverted->tamanho++;
        return;
    }
    if(inverted->fim->anterior != NULL && (inverted->fim->anterior->inverted.idDoc != index->idDoc)){
        inverted->fim->anterior = inverted->fim;
        inverted->fim->prox = (PonteiroIndex) malloc(sizeof(indeces));
        inverted->fim = inverted->fim->prox;
        inverted->fim->inverted = *index;
        inverted->fim->prox = NULL;
        inverted->tamanho++;
        return;
    }
    else{
        inverted->fim->inverted.qtde++;
    }
}
void sortIndex(invertedIndex *inverted){

}
void imprimeIndexs(invertedIndex *inverted){
    PonteiroIndex auxiliar = inverted->inicio;
    while (auxiliar!=NULL){
        printf("<%d,%d> ",auxiliar->inverted.qtde,auxiliar->inverted.idDoc);
        auxiliar = auxiliar->prox;
    }
}