//
// Created by duce on 11/09/2021.
//

#ifndef GTKTESTE_JANELABUSCA_H
#define GTKTESTE_JANELABUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <pthread.h>

#include "../../Dicionario.h"
#include "../../WordTad.h"
#include "../../treePatricia.h"
#include "../../arquivoManipulate.h"

#define ARQUIVO_JANELA_BUSCA "janelabusca.glade"
#define ID_JANELA_BUSCA "janela_busca"
#define ID_PESQUISA_JANELA_BUSCA "pesquisa_janela_busca"
#define MIN_LETRAS_ENTRADA 3
#define MAX_RESULTADOS_PREENCHIMENTO 8

// 'completion' deve permanecer global para que o autopreenchimento da busca funcione de forma adequada
GtkEntryCompletion *completion;
pthread_t thread_preenchimento;

const gchar *entrada;
char **resultados;
int *indice;

Word *termo_busca_patricia;

void inicializaJanelaBusca(GtkApplication *app, gpointer user_data);
void updatePesquisa(GtkWidget *widget, gpointer data);
void pegaResultadosParecidos(const gchar *entrada);
void *threadPreenchimento();
void buscaTermoNaPatricia(GtkWidget *widget, gpointer data);

#endif //GTKTESTE_JANELABUSCA_H
