//
// Created by duce on 12/09/2021.
//

#ifndef TRABALHO_1_JANELASELECAOPASTA_H
#define TRABALHO_1_JANELASELECAOPASTA_H

#define ARQUIVO_JANELA_SELECAO_PASTA "janelaselecaopasta.glade"
#define ID_JANELA_SELECAO_PASTA "janela_selecao_pasta"
#define ID_SELECAO_PASTA "selecionador_de_arquivo"
#define ID_DIRETORIO_SELECIONADO "diretorio_selecionado"

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <pthread.h>

#include "../../arquivoManipulate.h"

GtkWidget *janela_selecao_pasta;
GtkFileChooserButton *selecionador;
gchar *diretorio_selecionado;

void abrirJanelaSelecaoPasta(GtkApplication *app, gpointer userdata);
void destroyJanelaSelecaoPasta(GtkWidget *widget, gpointer data);
void selecionouPasta(GtkWidget *widget, gpointer data);
void* inicializaPatricia();

#endif //TRABALHO_1_JANELASELECAOPASTA_H
