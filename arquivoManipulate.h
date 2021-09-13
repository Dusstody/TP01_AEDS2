//
// Created by pedro on 22/08/2021.
//

#ifndef TRABALHO_1_ARQUIVOMANIPULATE_H
#define TRABALHO_1_ARQUIVOMANIPULATE_H

#include "treePatricia.h"
#include "view/janelas/JanelaSelecaoPasta.h"
#include <dirent.h>

typedef struct{
    int quantidade;
    char nomesArq[30];
    int *idDocs;
}arquivos;

TypeTree patricia;
char **palavras_patricia;
char **indices_patricia;

char* nomeBase(char *palavra);
int pontoTxt(char *palavra);
int idDoc(char *arquivo);
void leitura(char *Nome_arquivo,int arquivo,TypeTree *arvore);
void leiturateste();
void identifyTextos();
#endif //TRABALHO_1_ARQUIVOMANIPULATE_H
