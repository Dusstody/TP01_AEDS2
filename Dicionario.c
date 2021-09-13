//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
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
void printTSTSubtree(TSTNodePointer tree, char *buffer, int index,char *termos,char **Fill,int *position) {
    if (tree) {
        printTSTSubtree(tree->left, buffer, index, termos, Fill, position);
        buffer[index] = tree->character;

        if (tree->isEndOfString) {
            buffer[index + 1] = '\0';
            verify(termos,buffer,Fill,index,position);
        }

        printTSTSubtree(tree->middle, buffer, index + 1,termos, Fill, position);
        printTSTSubtree(tree->right, buffer, index, termos, Fill, position);
    }
}

// Imprime uma arvore TST
void mostraTST(TSTNodePointer tree) {
    char buffer[MAX_SIZE];
    mostraTSTSubTree(tree, buffer, 0);
}

void mostraTSTSubTree(TSTNodePointer node, char *buffer, int index) {
    if (node) {
        mostraTSTSubTree(node->left, buffer, index);
        buffer[index] = node->character;

        if (node->isEndOfString) {
            buffer[index + 1] = '\0';
            printf("%s\n", buffer);
        }

        mostraTSTSubTree(node->middle, buffer, index + 1);
        mostraTSTSubTree(node->right, buffer, index);
    }
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
void statsTST (TSTNodePointer tree) {
    printf("\t *** Dados da Arvore TST: *** \n");
    printf("Numero de nos TST: %d\n", nodeAmountTST(tree));
    printf("Altura da TST: %d\n", heightTST(tree));
    printf("\t ********* \n");
}

char** AutoFillTST(TSTNodePointer tree, char *termoPreenche, int *indice) {
    char *buffer = (char *) malloc(SIZE_LONGEST_WORD * sizeof(char));
    char **respostas = (char **) malloc(MAXTAM * sizeof(char));

    for (int i = 0; i < MAXTAM; ++i) {
        respostas[i] = (char *) malloc(SIZE_LONGEST_WORD * sizeof (char));
    }

    imprimeTermos(tree, termoPreenche, buffer,0, respostas, indice);

    free(buffer);
    return respostas;
}
void imprimeTermos(TSTNodePointer tree, char *termos, char* buffer, int index, char **Fill, int *position){
    if (tree) {
        printTSTSubtree(tree->left, buffer, index, termos, Fill, position);

        buffer[index] = tree->character;

        if (tree->isEndOfString) {
            buffer[index + 1] = '\0';
            verify(termos, buffer, Fill, index, position);
        }

        printTSTSubtree(tree->middle, buffer, index + 1, termos, Fill, position);
        printTSTSubtree(tree->right, buffer, index, termos, Fill, position);
    }
}

void verify (char *termo, char *stringC, char **Fill, int index, int *position) {
    if (strlen(termo) > strlen(stringC)) {
        return;
    } else {
        int count;
        count = 0;

        for (int i = 0; i < strlen(stringC); ++i) {
            if (stringC[i] == termo[i] && i < strlen(termo)) {
                count++;
            }
        }

        if(count != strlen(termo)){
            return;
        }

//        printf("%s\n",stringC);
        strcpy(Fill[(*position)++],stringC);
    }
}

void inicializaDicionario () {

    FILE *file;
    file = fopen("wordsDictionary.txt","r");

    if (file == NULL) {
        exit(1);
    } else {
        int *indice;
        char *palavra;

        dicionario = NULL;
        indice = (int*) malloc(sizeof (int)); *indice = 0;
        palavra = (char*) malloc(SIZE_LONGEST_WORD * sizeof(char));

        while (!feof(file)) {
            fscanf(file,"%s", palavra);

            insertNodeTST(&dicionario, palavra);
            //printf("%s\n", palavra);
        }

        free(palavra);
//        printTST(rootTST);

//        char **Fill = AutoFillTST(dicionario,"hospi",indice);
//        for (int i = 0; i < *indice; ++i) {
//            printf("%s\n", Fill[i]);
//        }
    }
}
