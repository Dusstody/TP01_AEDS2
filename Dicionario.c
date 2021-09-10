//
// Created by gabxn on 09/09/2021.
//

#include "Dicionario.h"

// Cria um no TST, alocando memoria e setando os dados iniciais
TSTNodePointer createNodeTST(TSTValue character) {
  TSTNodePointer node = (TSTNodePointer)malloc(sizeof(TSTNode));
  node->character = character;
  node->isEndOfString = 0;
  node->left = NULL;
  node->middle = NULL;
  node->right = NULL;
  return node;
}

// Insere um no na árvore TST, verificando as condições de tamanho da palavra e desvios
void insertNodeTST(TSTNodePointer *tree, char *word) {
  if (!(*tree))
    *tree = createNodeTST(*word);

  if ((*word) < (*tree)->character) {
    insertNodeTST(&((*tree)->left), word);
  } else if ((*word) > (*tree)->character) {
    insertNodeTST(&((*tree)->right), word);
  } else {
    if (*(word + 1))
      insertNodeTST(&((*tree)->middle), word + 1);
    else
      (*tree)->isEndOfString = 1;
  }
}

// Pesquisa uma palavra na arvore TST, percorrendo-a recursivamente até encontrar (ou) nao a palavra
int searchTST(TSTNodePointer tree, char *word, int *comparisons, int *height) {
  if (!tree)
    return 0;

  (*height)++;

  if (*word < (tree)->character) {
    (*comparisons)++;
    return searchTST(tree->left, word, comparisons, height);
  } else if (*word > (tree)->character) {
    *comparisons += 2;
    return searchTST(tree->right, word, comparisons, height);
  } else {
    if (*(word + 1) == '\0')
      return tree->isEndOfString;
    *comparisons += 3;
    return searchTST(tree->middle, word + 1, comparisons, height);
  }
}

// Percorre uma sub-arvore TST, chamando-a recursivamente
void printTSTSubtree(TSTNodePointer tree, char *buffer, int index,char *termos) {
  if (tree) {
    printTSTSubtree(tree->left, buffer, index,termos);
    buffer[index] = tree->character;
    if (tree->isEndOfString) {
      buffer[index + 1] = '\0';
      verify(termos,buffer);
    }
    printTSTSubtree(tree->middle, buffer, index + 1,termos);
    printTSTSubtree(tree->right, buffer, index,termos);
  }
}

// Imprime uma arvore TST
void printTST(TSTNodePointer tree) {
  char buffer[MAX_SIZE];
//  printTSTSubtree(tree, buffer, 0);
}

// Verifica o máximo entre dois números inteiros
int max(int a, int b) {
  return (a > b) ? a : b;
}

// Calcula a altura da árvore TST fornecida
int heightTST(TSTNodePointer tree) {
  if (tree == NULL)
    return -1;
  int leftHeight = heightTST(tree->left);
  int rightHeight = heightTST(tree->right);
  int middleHeight = heightTST(tree->middle);
  return 1 + max(max(leftHeight, middleHeight), rightHeight);
}

// Calcula a quantidade de nós da árvore TST fornecida
int nodeAmountTST(TSTNodePointer tree) {
  if (tree == NULL)
    return 0;
  return 1 + nodeAmountTST(tree->left) + nodeAmountTST(tree->middle) + nodeAmountTST(tree->right);
}

// Imprime dados estatísticos da árvore Patricia fornecida
void statsTST(TSTNodePointer tree) {
  printf("\t *** Dados da Arvore TST: *** \n");
  printf("Numero de nos TST: %d\n", nodeAmountTST(tree));
  printf("Altura da TST: %d\n", heightTST(tree));
  printf("\t ********* \n");
}

int AutoFillTST(TSTNodePointer tree, char *termoPreenche) {
    char *buffer = (char*) malloc(MAX_SIZE*sizeof(char));
    imprimeTermos(tree,termoPreenche,buffer,0);
}
void imprimeTermos(TSTNodePointer tree,char *termos,char* buffer,int index){
    if (tree) {
        printTSTSubtree(tree->left, buffer, index,termos);
        buffer[index] = tree->character;
        if (tree->isEndOfString) {
            buffer[index + 1] = '\0';
            verify(termos,buffer);
        }
        printTSTSubtree(tree->middle, buffer, index + 1,termos);
        printTSTSubtree(tree->right, buffer, index,termos);
    }
}
void verify(char *termo,char *stringC){
    if(strlen(termo) > strlen(stringC)){
        return;
    }
    else{
        int count = 0;
        for(int i = 0;i< strlen(stringC);i++){
            if(stringC[i] == termo[i] && i < strlen(termo)){
                count++;
            }
        }
        if(count == strlen(termo)){
            printf("%s\n",stringC);
        }
    }
}
