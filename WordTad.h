//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#ifndef TRABALHO_1_WORDTAD_H
#define TRABALHO_1_WORDTAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IndexInverted.h"


typedef struct Celula * Apontador;

typedef struct Celula{
    struct Celula *prox;
    char letra;
}WordLen;

typedef struct{
    Apontador inicio,fim;
    int tamanho;
    indexPalavra palavraIndex;
    invertedIndex index;
}Word;

void iniciaWord(Word *word);
void insereWord(Word *word,char *palavra);
int wordCompare(Word *word1,Word *word2);
char minLetter(char letra);
char letraPosition(int position,Word *word);
char letraCompare(char letra1,char letra2);
void insereLetra(Word *word,char letra);
void imprimeWord(Word *word);

char* pegaPalavra(Word *word, char *palavra);

#endif //TRABALHO_1_WORDTAD_H
