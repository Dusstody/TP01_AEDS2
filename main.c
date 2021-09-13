#include "treePatricia.h"
#include "arquivoManipulate.h"
#include "Dicionario.h"

#include "view/App.h"

int ac;
char **av;

void* threadInterface () {
    startApp(ac, av);
}

int main (int argc, char *argv[]){
//    identifyTextos();
//    leiturateste();

    inicializaDicionario();

    ac = argc;
    av = argv;

    pthread_t thread_interface;
    pthread_create(&thread_interface, NULL, threadInterface, NULL);
    pthread_join(thread_interface, NULL);

    return 0;
}

