//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#ifndef DICIONARIOTST_DICIONARIO_H
#define DICIONARIOTST_DICIONARIO_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 50
#define MAXTAM 100000
#define SIZE_LONGEST_WORD 50
#define MAX_AMOUNT_COMPLETION 10

typedef char TSTValue;
typedef struct TSTNode *TSTNodePointer;

typedef struct TSTNode {
  TSTValue character;

  // 1 se termina uma palavra no nó
  short isEndOfString : 1;
  TSTNodePointer left;
  TSTNodePointer middle;
  TSTNodePointer right;
} TSTNode;


TSTNodePointer dicionario;

/**
 Cria um nó TST, alocando memória e setando os dados iniciais
 @param character Caracter a ser inserido no nó
 @return Ponteiro para o nó criado
 */
TSTNodePointer createNodeTST(char character);


/**
 Insere um nó na árvore TST, verificando as condições de tamanho da palavra e desvios
 @param tree Ponteiro para a árvore TST a ser manipulada
 @param word Palavra a ser inserida na árvore
 */
void insertNodeTST(TSTNodePointer *tree, char *word);


/**
 Pesquisa uma palavra na árvore TST, percorrendo-a recursivamente até encontrar (ou não) a palavra
 @param tree Ponteiro para a árvore TST a ser percorrida
 @param word Palavra a ser buscada
 @param comparisons Ponteiro para um inteiro que salva o número de comparações feitas
 @param height Ponteiro para um inteiro que salva a altura percorrida
 @return Inteiro representando se a palavra foi encontrada (1) ou não
 */
int searchTST(TSTNodePointer tree, char *word, int *comparisons, int *height);

/**
 Percorre uma sub-árvore TST, chamando-a recursivamente
 @param tree Ponteiro para a sub-árvore a ser percorrida
 @param buffer Uma string de buffer para armazenar a palavra, ja que cada nó salva um caracter apenas
 @param index Indice da profundidade do buffer para percorrer a árvore
 */
void printTSTSubtree(TSTNodePointer tree, char *buffer, int index,char *termos,char **Fill,int *position);


/**
 Imprime uma árvore TST
 @param tree Ponteiro para a árvore a ser percorrida
 */
void printTST(TSTNodePointer tree);


/**
 Verifica o máximo entre dois números inteiros
 @param a Primeiro valor inteiro a ser comparado
 @param b Segundo valor inteiro a ser comparado
 @return O valor do maior inteiro - a ou b.
 */
int max(int a, int b);


/**
 Calcula a altura da árvore TST fornecida
 @param tree Ponteiro para a árvore TST a ser percorrida
 @return Altura da árvore TST percorrida
 */
int heightTST(TSTNodePointer tree);


/**
 Calcula a quantidade de nós da árvore TST fornecida
 @param tree Ponteiro para a árvore TST a ser percorrida
 @return Quantidade de nós percorridos na árvore
 */
int nodeAmountTST(TSTNodePointer tree);


/**
 Imprime dados estatísticos da árvore Patricia fornecida

 @param tree Ponteiro para a árvore a ser analisada
 */
void statsTST(TSTNodePointer tree);

void inicializaDicionario();

char** AutoFillTST(TSTNodePointer tree, char *termoPreenche,int *indice);
void imprimeTermos(TSTNodePointer tree,char *termos,char *buffer,int index,char **Fill,int *position);
void verify(char *termo,char *stringC,char **Fill,int index,int *position);

void mostraTSTSubTree(TSTNodePointer node, char *buffer, int index);
void mostraTST(TSTNodePointer tree);

#endif //DICIONARIOTST_DICIONARIO_H