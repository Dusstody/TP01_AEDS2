//
// Created by pedro on 18/08/2021.
//

#ifndef TRABALHO_1_TREEPATRICIA_H
#define TRABALHO_1_TREEPATRICIA_H

#include "IndexInverted.h"


typedef Word TipoChave;
typedef unsigned char TipoIndexAmp;
typedef unsigned char TipoAuxiliar;

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
TipoAuxiliar Bit(TipoIndexAmp position,TipoChave chave);
TypeTree CriaNoInt(int position,TypeTree *Esquerda,TypeTree *Direita);
TypeTree CriaNoExt(TipoChave chave);
int EExterno(TypeTree no);
int pesquisa(char *palavra,TypeTree no,char *flag);
int search(TipoChave chave,TypeTree no,char *flag);
TypeTree InsereEntre(TipoChave chave,TypeTree *no,int position);
TypeTree Insere(TipoChave chave,TypeTree *no);
void wordOnPatricia(treePatricia **no,TipoChave chave);


#endif //TRABALHO_1_TREEPATRICIA_H
