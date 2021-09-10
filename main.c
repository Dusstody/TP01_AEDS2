#include "treePatricia.h"
#include "arquivoManipulate.h"
#include "Dicionario.h"

int main(){
//    identifyTextos();
//    leiturateste();

    TSTNodePointer rootTST = NULL;

    FILE *file;
    file = fopen("wordsDictionary.txt","r");
    if(file == NULL){
        exit(1);
    }
    else{
        while (!feof(file)){
            char *palavra = (char*) malloc(50*sizeof(char));
            fscanf(file,"%s", palavra);
            insertNodeTST(&rootTST, palavra);
            //printf("%s\n", palavra);

            free(palavra);
        }
//        printTST(rootTST);
        AutoFillTST(rootTST,"victory");
    }

    return 0;
}

