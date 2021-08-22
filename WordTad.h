//
// Created by pedro on 18/08/2021.
//

#ifndef TRABALHO_1_WORDTAD_H
#define TRABALHO_1_WORDTAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int qtde;
    int idDoc;
}indexPalavra;

typedef struct Celula * Apontador;

typedef struct Celula{
    struct Celula *prox;
    char letra;
}WordLen;

typedef struct{
    Apontador inicio,fim;
    int tamanho;
    indexPalavra index;
}Word;

void iniciaWord(Word *word);
void insereWord(Word *word,char *palavra);
int wordCompare(Word *word1,Word *word2);
char minLetter(char letra);
unsigned char letraReturn(unsigned char position,Word *word);
char letraCompare(char letra1,char letra2);
void insereLetra(Word *word,char letra);
void imprimeWord(Word *word);

#endif //TRABALHO_1_WORDTAD_H
