//
// Created by pedro on 22/08/2021.
//

#include "arquivoManipulate.h"



int pontoTxt(char *palavra){
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

int idDoc(char *arquivo){
    for(int i = 0;i< strlen(arquivo);i++){
        if(arquivo[i] == '.'){
            return arquivo[i-1] - '0';
        }
    }
}

char* nomeBase(char *palavra){
    char *palavraBase = (char*) malloc((strlen(palavra) - 3) *sizeof(char));
    for(int i = 0;i< strlen(palavra);i++){
        if(palavra[i+1] == '.'){
            break;
        }
        palavraBase[i] = palavra[i];
    }
    return palavraBase;
}

void identifyTextos(){
    DIR *dir;
    char diretorio[50];
    struct dirent *lsdir;
    printf("Digite o diretorio dos arquivos (.txt) para leitura (usar uma pasta com apenas os arquivos de texto):");
    scanf("%s",diretorio);
    dir = opendir(diretorio);
    TypeTree arvore;
    iniciaPatricia(&arvore);
    arquivos arquivosNomes;
    arquivosNomes.quantidade = 0;
    if(dir == NULL){
        printf("diretorio inexistente");
    }
    /* print all the files and directories within directory */
    else {
        while ((lsdir = readdir(dir)) != NULL) {
            if(pontoTxt(lsdir->d_name) == 1) {
                if(arquivosNomes.quantidade == 0) {
                    char *nome = nomeBase(lsdir->d_name);
                    strcpy(arquivosNomes.nomesArq, nome);
                }
                char *name_arq = (char*) malloc(60*sizeof (char));
                strcpy(name_arq,diretorio);
                strcat(name_arq,"/");
                strcat(name_arq,lsdir->d_name);
                arquivosNomes.quantidade++;
                int arquivo = idDoc(lsdir->d_name);
                leitura(name_arq,arquivo,&arvore);
                free(name_arq);
            }
        }
    }
    closedir(dir);
//    imprimeArvore(arvore);
    busca("quer todos",arvore,arquivosNomes.quantidade,arquivosNomes.nomesArq);
}

//void leiturateste(){
//    FILE *file,*file1,*file2;
//    file = fopen("texto1.txt","r");
//    file1 = fopen("texto2.txt","r");
//    file2 = fopen("texto3.txt","r");
//    int arquivo = 1;
//    if(file == NULL || file1 == NULL || file2 == NULL){
//        exit(1);
//    }
//    else{
//        TypeTree arvore;
//        iniciaPatricia(&arvore);
//        while (!feof(file)){
//            Word palavraIn;
//            iniciaWord(&palavraIn);
//            char *palavra = (char*) malloc(30*sizeof(char));
//            fscanf(file,"%s",palavra);
//            insereWord(&palavraIn,palavra);
//            palavraIn.palavraIndex.idDoc = arquivo;
//            wordOnPatricia(&arvore,palavraIn);
//            free(palavra);
//        }
//        arquivo++;
//        while (!feof(file1)){
//            Word palavraIn;
//            iniciaWord(&palavraIn);
//            char *palavra = (char*) malloc(30*sizeof(char));
//            fscanf(file1,"%s",palavra);
//            insereWord(&palavraIn,palavra);
//            palavraIn.palavraIndex.idDoc = arquivo;
//            wordOnPatricia(&arvore,palavraIn);
//            free(palavra);
//        }
//        arquivo++;
//        while (!feof(file2)){
//            Word palavraIn;
//            iniciaWord(&palavraIn);
//            char *palavra = (char*) malloc(50*sizeof(char));
//            fscanf(file2,"%s",palavra);
//            insereWord(&palavraIn,palavra);
//            palavraIn.palavraIndex.idDoc = arquivo;
//            wordOnPatricia(&arvore,palavraIn);
//            free(palavra);
//        }
//        imprimeArvore(arvore);
//        busca("casa",arvore);
//    }
//}
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
            char *palavra = (char*) malloc(30*sizeof(char));
            fscanf(file,"%s",palavra);
            insereWord(&palavraIn,palavra);
            palavraIn.palavraIndex.idDoc = arquivo;
            wordOnPatricia(arvore,palavraIn);
            free(palavra);
        }
    }
}