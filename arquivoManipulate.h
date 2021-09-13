//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
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
arquivos files;
char **palavras_patricia;
char **indices_patricia;

char* nomeBase(char *palavra);
int pontoTxt(char *palavra);
int idDoc(char *arquivo);
void leitura(char *Nome_arquivo,int arquivo,TypeTree *arvore);
void leiturateste();
void identifyTextos();
#endif //TRABALHO_1_ARQUIVOMANIPULATE_H
