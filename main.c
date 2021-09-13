//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

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

    ac = argc;
    av = argv;

    pthread_t thread_interface;
    pthread_create(&thread_interface, NULL, threadInterface, NULL);
    pthread_join(thread_interface, NULL);

    return 0;
}

