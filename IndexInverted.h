//
// Created by pedro on 19/08/2021.
//

#ifndef TRABALHO_1_INDEXINVERTED_H
#define TRABALHO_1_INDEXINVERTED_H

#include "WordTad.h"


typedef struct CelulaIndex *PonteiroIndex;

typedef struct CelulaIndex{
    struct CelulaIndex *prox;
    Word palavra;
}indeces;

typedef struct{
    PonteiroIndex inicio,fim;
    int tamanho;
}invertedIndex;

void startIndex(invertedIndex *inverted);
void putIndex(invertedIndex *inverted,Word *palavra);
void sortIndex(invertedIndex *inverted);
void imprimeIndexs(invertedIndex *inverted);



#endif //TRABALHO_1_INDEXINVERTED_H
