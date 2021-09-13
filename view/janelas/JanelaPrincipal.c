//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#include "JanelaPrincipal.h"

void dialogoAbrirTerminal(GtkWidget *widget, gpointer data, char *message) {
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(
            GTK_WINDOW(janela_principal), GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,
            "%s", message
    );

    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}

void destroyJanelaPrincipal(GtkWidget *widget, gpointer data) {
    gtk_widget_destroy(widget);
    g_application_quit(g_application_get_default());
}

void abrirJanelaBusca(GtkWidget *widget, gpointer data) {
    inicializaJanelaBusca(GTK_APPLICATION(g_application_get_default()), data);
}

void* inicializaPatricia() {
    identifyTextos();
}

void abrirJanelaIndiceInvertido(GtkWidget *widget, gpointer data) {
    inicializaPatricia();
    dialogoAbrirTerminal(widget, data, "Índice invertido construído com sucesso!");
}

void imprimirIndiceInvertido(GtkWidget *widget, gpointer data) {
    imprimeArvore(patricia);
    dialogoAbrirTerminal(widget, data, "Imprimido! Cheque o terminal!");
}

void inserirPalavrasTST(GtkWidget * widget, gpointer data) {
    inicializaDicionario();
    dialogoAbrirTerminal(widget, data, "Palavras Inseridas com sucesso!");
}

void imprimirTST(GtkWidget *widget, gpointer data) {
    mostraTST(dicionario);
    dialogoAbrirTerminal(widget, data, "Imprimido! Cheque o terminal!");
}

void inicializaJanelaPrincipal(GtkApplication *app, gpointer userdata){
    GtkBuilder *builder;
    builder = gtk_builder_new_from_file(ARQUIVO_JANELA_PRINCIPAL);

    gtk_builder_add_callback_symbols(
                builder,
                "onDestroy", G_CALLBACK(destroyJanelaPrincipal),
                "abrirJanelaBusca", G_CALLBACK(abrirJanelaBusca),
                "abrirJanelaIndiceInvertido", G_CALLBACK(abrirJanelaIndiceInvertido),
                "inserirPalavrasTST", G_CALLBACK(inserirPalavrasTST),
                "imprimirIndiceInvertido", G_CALLBACK(imprimirIndiceInvertido),
                "imprimirTST", G_CALLBACK(imprimirTST),
                NULL
            );
    gtk_builder_connect_signals(builder, NULL);

    janela_principal = gtk_application_window_new(app);
    janela_principal = GTK_WIDGET(gtk_builder_get_object(builder, ID_JANELA_PRINCIPAL));

    gtk_widget_show_all(janela_principal);

    abrirJanelaSelecaoPasta(app, userdata);
}
