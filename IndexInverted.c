//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
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

indexPalavra *sortIndex(invertedIndex *inverted){
    indexPalavra *indexes = (indexPalavra*) malloc(inverted->tamanho * sizeof(indexPalavra));
    PonteiroIndex aux1 = inverted->inicio;
    int position = 0;
    while (aux1!=NULL){
        indexes[position] = aux1->inverted;
        aux1 = aux1->prox;
        position++;
    }
    int j ;
    for (int i = 1; i < inverted->tamanho; i++)
    {
        indexPalavra aux = indexes[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( aux.idDoc < indexes[j].idDoc ) )
        {
            indexes[j + 1] = indexes[j];
            j--;
        }
        indexes[j + 1] = aux;
    }
    return indexes;
}

int numeroOcorrencias(invertedIndex *inverted,int idDoc){
    PonteiroIndex auxiliar = inverted->inicio;
    while (auxiliar != NULL){
        if(idDoc == auxiliar->inverted.idDoc){
            return auxiliar->inverted.qtde;
        }
        auxiliar = auxiliar->prox;
    }
    return 0;
}

int idDocBe(invertedIndex *inverted,int idDoc){
    PonteiroIndex auxiliar = inverted->inicio;
    while (auxiliar != NULL){
        if(idDoc == auxiliar->inverted.idDoc){
            return 1;
        }
        auxiliar = auxiliar->prox;
    }
    return 0;
}
void imprimeIndexs(invertedIndex *inverted){
    indexPalavra *indices = sortIndex(inverted);
    for(int i = 0;i<inverted->tamanho;i++){
        printf("<%d,%d> ",indices[i].qtde,indices[i].idDoc);
    }
}