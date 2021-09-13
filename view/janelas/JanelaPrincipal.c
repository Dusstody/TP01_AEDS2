//
// Created by duce on 11/09/2021.
//

#include "JanelaPrincipal.h"

void destroyJanelaPrincipal(GtkWidget *widget, gpointer data) {
    gtk_widget_destroy(widget);
    g_application_quit(g_application_get_default());
}

void abrirJanelaBusca(GtkWidget *widget, gpointer data) {
    inicializaJanelaBusca(GTK_APPLICATION(g_application_get_default()), data);
}

void abrirJanelaIndiceInvertido(GtkWidget *widget, gpointer data) {
//    inicializaJanelaIndiceInvertido(GTK_APPLICATION(g_application_get_default()), data);

    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(
            GTK_WINDOW(janela_principal), GTK_DIALOG_DESTROY_WITH_PARENT,
                GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,
                "Índice invertido construído."
            );

    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}

void imprimirIndiceInvertido(GtkWidget *widget, gpointer data) {
    imprimeArvore(patricia);
}

void inicializaJanelaPrincipal(GtkApplication *app, gpointer userdata){
    GtkBuilder *builder;
    builder = gtk_builder_new_from_file(ARQUIVO_JANELA_PRINCIPAL);

    gtk_builder_add_callback_symbols(
                builder,
                "onDestroy", G_CALLBACK(destroyJanelaPrincipal),
                "abrirJanelaBusca", G_CALLBACK(abrirJanelaBusca),
                "abrirJanelaIndiceInvertido", G_CALLBACK(abrirJanelaIndiceInvertido),
                "imprimirIndiceInvertido", G_CALLBACK(imprimirIndiceInvertido),
                NULL
            );
    gtk_builder_connect_signals(builder, NULL);

    janela_principal = gtk_application_window_new(app);
    janela_principal = GTK_WIDGET(gtk_builder_get_object(builder, ID_JANELA_PRINCIPAL));

    gtk_widget_show_all(janela_principal);

    abrirJanelaSelecaoPasta(app, userdata);
}
