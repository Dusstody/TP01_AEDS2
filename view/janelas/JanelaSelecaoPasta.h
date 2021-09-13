//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
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

#endif //TRABALHO_1_JANELASELECAOPASTA_H
