//
// Created by duce on 12/09/2021.
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
