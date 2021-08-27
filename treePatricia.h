//
// Created by pedro on 18/08/2021.
//

#ifndef TRABALHO_1_TREEPATRICIA_H
#define TRABALHO_1_TREEPATRICIA_H

#include "WordTad.h"
#define TRUE 1
#define FALSE 0


typedef Word TipoChave;

typedef struct {
    unsigned char position;
    char letra;
}TipoIndexAmp;

typedef enum{
    interno,externo
}TypeOfNo;

typedef struct typePartition * TypeTree;

typedef struct typePartition{
    TypeOfNo tipo;
    union{
       struct{
           TipoIndexAmp index;
           TypeTree esquerda,direita;
       }NoInterno;
       TipoChave chave;
    }No;


}treePatricia;

void iniciaPatricia(TypeTree *noRaiz);
TypeTree CriaNoInt(char letter,int position,TypeTree *Esquerda,TypeTree *Direita);
TypeTree CriaNoExt(TipoChave chave);
int EExterno(TypeTree no);
void pesquisa(char *palavra,TypeTree no);
void search(TipoChave chave,TypeTree no);
TypeTree InsereEntre(TipoChave chave,TypeTree *no,int position);
TypeTree Insere(TipoChave chave,TypeTree *no);
void wordOnPatricia(treePatricia **no,TipoChave chave);
void imprimeArvore(treePatricia *no);


char Caractere(short i,TipoChave chave);
int MaiorIgual(char a, char b);


#endif //TRABALHO_1_TREEPATRICIA_H
