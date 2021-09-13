//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#ifndef TRABALHO_1_INDEXINVERTED_H
#define TRABALHO_1_INDEXINVERTED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int qtde;
    int idDoc;
}indexPalavra;

typedef struct CelulaIndex *PonteiroIndex;

typedef struct CelulaIndex{
    struct CelulaIndex *prox;
    struct CelulaIndex *anterior;
    indexPalavra inverted;
}indeces;

typedef struct{
    PonteiroIndex inicio,fim;
    int tamanho;
}invertedIndex;

void startIndex(invertedIndex *inverted);
void putIndex(invertedIndex *inverted,indexPalavra *index);
indexPalavra *sortIndex(invertedIndex *inverted);
void imprimeIndexs(invertedIndex *inverted);
int idDocBe(invertedIndex *inverted,int idDoc);
int numeroOcorrencias(invertedIndex *inverted,int idDoc);


#endif //TRABALHO_1_INDEXINVERTED_H
