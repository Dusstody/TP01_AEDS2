//
// Created by pedro on 22/08/2021.
//

#ifndef TRABALHO_1_ARQUIVOMANIPULATE_H
#define TRABALHO_1_ARQUIVOMANIPULATE_H
#include "treePatricia.h"
#include <dirent.h>

typedef struct CelulaNomesTextos *ApontaNomes;

typedef struct CelulaNomesTextos{
    struct CelulaNomesTextos *prox;
    char nome[30];
}celTextos;

typedef struct{
    ApontaNomes inicio,fim;
    int tamanho;
}textos;

void iniciaListaTextos(textos *nomes);
void insereNome(textos *nomes,char *nome);
void executaLeitura(textos *nomes);
void desaloca(textos *nomes);

int pontoTxt(char *palavra);
void leitura(char *Nome_arquivo,int arquivo,TypeTree *arvore);
void leiturateste();
void identifyTextos();
#endif //TRABALHO_1_ARQUIVOMANIPULATE_H
