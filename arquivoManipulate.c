//
// Created by pedro on 22/08/2021.
//

#include "arquivoManipulate.h"
void iniciaListaTextos(textos *nomes){
    nomes->inicio = NULL;
    nomes->fim = NULL;
    nomes->tamanho = 0;
}
void insereNome(textos *nomes,char *nome){
    if(nomes->fim == NULL){
        nomes->fim = (ApontaNomes) malloc(sizeof(celTextos));
        nomes->inicio = nomes->fim;
    }
    else{
        nomes->fim->prox = (ApontaNomes) malloc(sizeof(celTextos));
        nomes->fim = nomes->fim->prox;
    }
    strcpy(nomes->fim->nome,nome);
    nomes->fim->prox = NULL;
    nomes->tamanho++;
}
void executaLeitura(textos *nomes){
    TypeTree arvore;
    iniciaPatricia(&arvore);
    ApontaNomes auxiliar = nomes->inicio;
    int arquivo = 1;
    while (auxiliar != NULL){
        leitura(auxiliar->nome,arquivo,&arvore);
        auxiliar = auxiliar->prox;
        arquivo++;
    }
    imprimeArvore(arvore);
}
void desaloca(textos *nomes){

}




int pontoTxt(char *palavra){//ainda não funciona
    int tamanho = strlen(palavra);
    char verify[4];
    int position = 0;
    char flag;
    for(int i = 0;i< tamanho;i++){
        if(palavra[i] == '.' && ((i+1)<tamanho)){
            if(palavra[i+1] == 't') {
                verify[position] = palavra[i];
                position++;
            }
        }
        if(palavra[i] == 't' && (flag == '.' || flag == 'x') && (position == 1 || position == 3)){
            verify[position] = palavra[i];
            position++;
        }
        if(palavra[i] == 'x' && flag == 't' && position == 2){
            verify[position] = palavra[i];
            position++;
        }
        flag = palavra[i];
    }
    if(strcmp(".txt",verify) == 0){
        return 1;
    }
    return 0;
}
void identifyTextos(){
    DIR *dir;
    char diretorio[50];
    struct dirent *lsdir;
    printf("Digite o diretorio dos arquivos (.txt) para leitura (recomenda-se usar uma pasta vazia):");
    scanf("%s",diretorio);
    dir = opendir(diretorio);
    textos txts;
    iniciaListaTextos(&txts);
    if(dir == NULL){
        printf("diretorio inexistente");
    }
    /* print all the files and directories within directory */
    else {
        while ((lsdir = readdir(dir)) != NULL) {
            if(pontoTxt(lsdir->d_name) == 1) {
                insereNome(&txts,lsdir->d_name);
            }
        }
    }
    closedir(dir);
    executaLeitura(&txts);
}
void leiturateste(){//falta arrumar os indices invertidos ainda... ta dando problema para quando tem mais de 1 arquivo
    FILE *file,*file1;
    file = fopen("texto1.txt","r");
    file1 = fopen("texto2.txt","r");
    int arquivo = 1;
    if(file == NULL || file1 == NULL){
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
            palavraIn.palavraIndex.idDoc = arquivo;
            wordOnPatricia(&arvore,palavraIn);
            free(palavra);
        }
        arquivo++;
        while (!feof(file1)){
            Word palavraIn;
            iniciaWord(&palavraIn);
            char *palavra = (char*) malloc(50*sizeof(char));
            fscanf(file1,"%s",palavra);
            insereWord(&palavraIn,palavra);
            palavraIn.palavraIndex.idDoc = arquivo;
            wordOnPatricia(&arvore,palavraIn);
            free(palavra);
        }
        imprimeArvore(arvore);
    }
}
void leitura(char *Nome_arquivo,int arquivo,TypeTree *arvore){
    FILE *file;
    file = fopen(Nome_arquivo,"r");
    if(file == NULL){
        exit(1);
    }
    else{
        while (!feof(file)){
            Word palavraIn;
            iniciaWord(&palavraIn);
            char *palavra = (char*) malloc(50*sizeof(char));
            fscanf(file,"%s",palavra);
            insereWord(&palavraIn,palavra);
            palavraIn.palavraIndex.idDoc = arquivo;
            wordOnPatricia(arvore,palavraIn);
            free(palavra);
        }
    }
}