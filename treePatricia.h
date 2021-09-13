//
// Created by pedro on 18/08/2021.
//

#ifndef TRABALHO_1_TREEPATRICIA_H
#define TRABALHO_1_TREEPATRICIA_H

#include "WordTad.h"
#include <math.h>
#define TRUE 1
#define FALSE 0


typedef Word TipoChave;

typedef struct{
    char nomeDoc[30];
    double relevancia;
    int idDoc;
}relevance;

typedef struct {
    int position;
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
void busca(char *termoBusca, TypeTree no,int qtdDocumento,char nomeBase[20],int *idDocs);
double relevancia(TypeTree no,TipoChave *termos,int qtdTermosBusca,int idDoc,int qtdDcumentos);
relevance *ponderation( TypeTree no,int qtdDocumento,TipoChave *termos,int qtdTermosBusca,char nomeBase[20],int *idDocs);
double peso(int numeroOcorrencias,int qtdDocContem,int qtdDocumento);
void qtdTermos(TypeTree no,int idDoc,int *quantidadeInitEnd);
TipoChave* search(TipoChave chave,TypeTree no);
TypeTree InsereEntre(TipoChave chave,TypeTree *no,int position,char letraNointerno);
TypeTree Insere(TipoChave chave,TypeTree *no);
void wordOnPatricia(treePatricia **no,TipoChave chave);
void imprimeArvore(treePatricia *no);
char Caractere(int i,TipoChave chave);
int Relacao(char a, char b);

char** pegaPalavras(treePatricia *no, char **palavras, int index);

void insercaoOrdena(relevance *relevancias,int tamanho);


#endif //TRABALHO_1_TREEPATRICIA_H
