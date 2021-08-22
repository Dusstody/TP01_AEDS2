//
// Created by pedro on 18/08/2021.
//

#include "treePatricia.h"

void iniciaPatricia(TypeTree *noRaiz){
    *noRaiz = NULL;
}
void wordOnPatricia(treePatricia **no,TipoChave chave){
    if((*no) != NULL){
        int insere = search(chave,*no,"sum");
        if (insere == 1){
            *no = Insere(chave,no);
        }
    }
    *no = Insere(chave,no);
}

TypeTree InsereEntre(TipoChave chave,TypeTree *no,int position){
    TypeTree aux;
    if (EExterno(*no) || position < (*no)->No.NoInterno.index){//Cria um novo no externo
        aux = CriaNoExt(chave);
        if (Bit(position,chave) == 1)
            return (CriaNoInt(position,no,&aux));
        else return (CriaNoInt(position,&aux,no));
    }
    else{
        if (Bit((*no)->No.NoInterno.index,chave) == 1){
            (*no)->No.NoInterno.direita = InsereEntre(chave,&(*no)->No.NoInterno.direita,position);
        }
        else{
            (*no)->No.NoInterno.esquerda = InsereEntre(chave,&(*no)->No.NoInterno.esquerda,position);
        }
        return (*no);
    }
}


TypeTree Insere(TipoChave chave,TypeTree *no){
    TypeTree aux;
    int i;
    if(*no == NULL){
        return (CriaNoExt(chave));
    }
    else{
        aux = *no;
        while (!EExterno(aux)){
            if(Bit(aux->No.NoInterno.index,chave) == 1){
                aux = aux->No.NoInterno.direita;
            }
            else{
                aux = aux->No.NoInterno.esquerda;
            }
            //acha o primeiro bit diferente
            i = 1;
        }
        while ((i<=chave.tamanho)&(Bit((int)i,chave) == Bit((int)i,aux->No.chave)))
            i++;
        if(chave.tamanho == aux->No.chave.tamanho){
            if (i > chave.tamanho){
                return *no;
            }
            else return (InsereEntre(chave,no, i));
        }
        return (InsereEntre(chave,no, i));
    }
}

TipoAuxiliar Bit(TipoIndexAmp position,TipoChave chave){
    // Retorna o i-esimo bit da chave k a partir da esquerda
    int aux;
    if (position == 0){
        return 0;
    }
    else{
        aux = letraReturn(position,&chave);
        for (int j = 1;j <= chave.tamanho - position;j++){
            aux /= 2;
        }
        return (aux & 1);
    }
}

int EExterno(TypeTree no){
    return (no->tipo == externo);
}

TypeTree CriaNoInt(int position,TypeTree *Esquerda,TypeTree *Direita){
    TypeTree aux;
    aux = (TypeTree) malloc(sizeof(treePatricia));
    aux->tipo = interno;
    aux->No.NoInterno.esquerda = *Esquerda;
    aux->No.NoInterno.direita = *Direita;
    aux->No.NoInterno.index = position;
    return aux;
}
TypeTree CriaNoExt(TipoChave chave){// aqui vamos incrementar os valores se caso a chave ja exista na arvore
    TypeTree aux;
//    imprimeWord(&chave);
//    printf("\n");
    aux = (TypeTree) malloc(sizeof(treePatricia));
    aux->tipo = externo;
    aux->No.chave = chave;
    return aux;
}

int pesquisa(char *palavra,TypeTree no,char *flag){
    TipoChave chave;
    iniciaWord(&chave);
    insereWord(&chave,palavra);
    return search(chave,no,flag);
}
int search(TipoChave chave,TypeTree no,char *flag){
    Word palavraVazia;
    iniciaWord(&palavraVazia);
    if (EExterno(no)){
        if (wordCompare(&chave,&no->No.chave) == 0){
            if(strcmp(flag,"imprimir") == 0){
                imprimeWord(&no->No.chave);
            }
            if(strcmp(flag,"sum") == 0){
                no->No.chave.index.qtde++;
            }
            return 0 ;
        }
        else{
            return 1;
        }
    }
    if (Bit(no->No.NoInterno.index,chave) == 0)
        search(chave,no->No.NoInterno.esquerda,flag);
    else search(chave,no->No.NoInterno.direita,flag);
}