//
// Created by pedro on 22/08/2021.
//

#include "arquivoManipulate.h"


void leitura(){
    FILE *file;
    char *Nome_arquivo = "texto1.txt";
    file = fopen(Nome_arquivo,"r");
    int arquivo = 1;
    if(file == NULL){
        exit(1);
    }
    else{
        TypeTree arvore;
        iniciaPatricia(&arvore);
        while (!feof(file)){
            Word palavraIn;
            iniciaWord(&palavraIn);
            char *palavra = (char*) malloc(50*sizeof(char));
            fscanf(file,"%s",palavra);
            insereWord(&palavraIn,palavra);
            palavraIn.index.idDoc = arquivo;
            wordOnPatricia(&arvore,palavraIn);
            free(palavra);
        }
        pesquisa("casa",arvore,"imprimir");
    }
}