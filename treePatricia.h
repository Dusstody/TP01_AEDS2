//
// Created by pedro on 18/08/2021.
//

#ifndef TRABALHO_1_TREEPATRICIA_H
#define TRABALHO_1_TREEPATRICIA_H

#include "WordTad.h"


typedef Word TipoChave;
typedef unsigned char TipoIndexAmp;
typedef char Letra;
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
           Letra letter;
           TypeTree esquerda,direita;
       }NoInterno;
       TipoChave chave;
    }No;


}treePatricia;

void iniciaPatricia(TypeTree *noRaiz);
TipoAuxiliar Bit(TipoIndexAmp position,TipoChave chave);
TypeTree CriaNoInt(char letter,int position,TypeTree *Esquerda,TypeTree *Direita);
TypeTree CriaNoExt(TipoChave chave);
int EExterno(TypeTree no);
void pesquisa(char *palavra,TypeTree no);
void search(TipoChave chave,TypeTree no);
TypeTree InsereEntre(TipoChave chave,TypeTree *no,int position);
TypeTree Insere(TipoChave chave,TypeTree *no);
void wordOnPatricia(treePatricia **no,TipoChave chave);
void imprimeArvore(treePatricia *no);


#endif //TRABALHO_1_TREEPATRICIA_H
