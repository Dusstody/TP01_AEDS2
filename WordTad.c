//
// Created by pedro on 18/08/2021.
//

#include "WordTad.h"

void iniciaWord(Word *word){
    word->inicio = NULL;
    word->fim = NULL;
    word->tamanho = 0;
    startIndex(&word->index);
}
void insereLetra(Word *word,char letra){
    if (word->fim == NULL){
        word->fim = (Apontador) malloc(sizeof(WordLen));
        word->inicio = word->fim;
    }
    else{
        word->fim->prox = (Apontador) malloc(sizeof(WordLen));
        word->fim = word->fim->prox;
    }
    word->fim->letra = letra;
    word->fim->prox = NULL;
    word->tamanho++;
}
char minLetter(char letra){
    char letraReturn;
    int valor = letra;
    char letraAux = valor + 32;
    if (letraCompare(letra,letraAux) != '\0'){
        letraReturn = letraAux;
    }
    else{
        letraReturn = letra;
    }
    return letraReturn;
}
void insereWord(Word *word,char *palavra){
    unsigned long tamanho = strlen(palavra);
    for (unsigned long i = 0;i<tamanho;i++){
        if(palavra[i] != '.' && palavra[i] != '?' && palavra[i] != ',' && palavra[i] != '!' && palavra[i] != '(' && palavra[i] != ')' && palavra[i] != ';' && palavra[i] != ':')
            insereLetra(word, minLetter(palavra[i]));
    }
    word->palavraIndex.qtde = 1;
}
char letraPosition(int position,Word *word){
    int valor = 0;//valor de i começa de 1
    Apontador auxiliar = word->inicio;
    if(position <= word->tamanho){
        while (auxiliar != NULL){
            if(valor == position){
                return auxiliar->letra;
            }
            valor = valor + 1;
            auxiliar = auxiliar->prox;
        }
    }
    return NULL;
}

int wordCompare(Word *word1,Word *word2){
    Apontador auxiliarWord1,auxiliarWord2;
    auxiliarWord1 = word1->inicio;
    auxiliarWord2 = word2->inicio;
    int valor = 0;
    if(word1->tamanho != word2->tamanho){
        return 1;
    }
    else{
        while (auxiliarWord1 != NULL){
            char letra = letraCompare(auxiliarWord1->letra,auxiliarWord2->letra);
            if (letra != '\0'){
                valor++;
            }
            auxiliarWord2 = auxiliarWord2->prox;
            auxiliarWord1 = auxiliarWord1->prox;
        }
        if (valor == word1->tamanho){
            return 0;
        }
    }
    return 1;
}
char letraCompare(char letra1,char letra2){
    int valorLetra1 = letra1 + '0';
    int valorLetra2 = letra2 + '0';
    if (valorLetra1 > valorLetra2){
        if (valorLetra2 + 32 == valorLetra1){
            return letra1;
        }
    }
    else if (valorLetra2 > valorLetra1){
        if (valorLetra1 + 32 == valorLetra2){
            return letra2;
        }
    }
    else{
        return letra2;
    }
    return '\0';
}
void imprimeWord(Word *word){
    Apontador auxiliar = word->inicio;
    printf("Palavra: ");
    while (auxiliar != NULL){
        printf("%c",auxiliar->letra);
        auxiliar = auxiliar->prox;
    }
    printf(" ");
//    printf("<%d,%d>",word->palavraIndex.qtde,word->palavraIndex.idDoc);
    imprimeIndexs(&word->index);
    printf("\n");
}