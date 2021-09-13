//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#ifndef TRABALHO_1_JANELAINDICEINVERTIDO_H
#define TRABALHO_1_JANELAINDICEINVERTIDO_H

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <pthread.h>

#define ARQUIVO_JANELA_INDICE_INVERTIDO "janelaindiceinvertido.glade"
#define ID_JANELA_INDICE_INVERTIDO "janela_indice_invertido"
#define ID_TREE_VIEW "table_view"

void inicializaJanelaIndiceInvertido(GtkApplication *app, gpointer user_data);


#endif //TRABALHO_1_JANELAINDICEINVERTIDO_H
