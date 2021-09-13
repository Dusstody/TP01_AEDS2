//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#ifndef GTKTESTE_JANELAPRINCIPAL_H
#define GTKTESTE_JANELAPRINCIPAL_H

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "JanelaSelecaoPasta.h"
#include "JanelaBusca.h"
#include "JanelaIndiceInvertido.h"

#define ARQUIVO_JANELA_PRINCIPAL "janelaprincipal.glade"
#define ID_JANELA_PRINCIPAL "janela_principal"

GtkWidget *janela_principal;

void inicializaJanelaPrincipal(GtkApplication *app, gpointer userdata);
void destroyJanelaPrincipal(GtkWidget *widget, gpointer data);
void* inicializaPatricia();
void abrirJanelaBusca(GtkWidget *widget, gpointer data);
void abrirJanelaIndiceInvertido(GtkWidget *widget, gpointer data);
void imprimirIndiceInvertido(GtkWidget *widget, gpointer data);
void imprimirTST(GtkWidget *widget, gpointer data);
void inserirPalavrasTST(GtkWidget * widget, gpointer data);

void dialogoAbrirTerminal(GtkWidget *widget, gpointer data, char *message);

#endif //GTKTESTE_JANELAPRINCIPAL_H
