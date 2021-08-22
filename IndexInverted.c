//
// Created by pedro on 19/08/2021.
//

#include "IndexInverted.h"


void startIndex(invertedIndex *inverted){
    inverted->inicio = NULL;
    inverted->fim = inverted->inicio;
    inverted->tamanho = 0;
}
void putIndex(invertedIndex *inverted,Word *palavra){
    if(inverted->fim == NULL){
        inverted->fim = (PonteiroIndex) malloc(sizeof(indeces));
        inverted->inicio = inverted->fim;
    }
    else{
        inverted->fim->prox = (PonteiroIndex) malloc(sizeof(indeces));
        inverted->fim = inverted->fim->prox;
    }
    inverted->fim->palavra = *palavra;
    inverted->fim->prox = NULL;
    inverted->tamanho++;
}
void sortIndex(invertedIndex *inverted){

}
void imprimeIndexs(invertedIndex *inverted){
    PonteiroIndex auxiliar = inverted->inicio;
    while (auxiliar!=NULL){
        imprimeWord(&auxiliar->palavra);
        auxiliar = auxiliar->prox;
    }
}