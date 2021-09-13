//
// Created by duce on 11/09/2021.
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
void abrirJanelaBusca(GtkWidget *widget, gpointer data);
void abrirJanelaIndiceInvertido(GtkWidget *widget, gpointer data);
void imprimirIndiceInvertido(GtkWidget *widget, gpointer data);

#endif //GTKTESTE_JANELAPRINCIPAL_H
