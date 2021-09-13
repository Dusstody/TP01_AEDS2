//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#include "JanelaSelecaoPasta.h"

void destroyJanelaSelecaoPasta(GtkWidget *widget, gpointer data) {
    gtk_widget_destroy(widget);
}

void selecionouPasta(GtkWidget *widget, gpointer data) {
    diretorio_selecionado = (char *)gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(selecionador));
    g_print("%s\n", diretorio_selecionado);

    destroyJanelaSelecaoPasta(janela_selecao_pasta, data);
}

void abrirJanelaSelecaoPasta(GtkApplication *app, gpointer userdata) {

    GtkLabel *diretorio_label;
    GtkBuilder *builder;

    builder = gtk_builder_new_from_file(ARQUIVO_JANELA_SELECAO_PASTA);
    gtk_builder_add_callback_symbols(
                builder,
                "destroyJanelaSelecaoPasta", G_CALLBACK(destroyJanelaSelecaoPasta),
                "selecionouPasta", G_CALLBACK(selecionouPasta),
                NULL
            );
    gtk_builder_connect_signals(builder, NULL);

    janela_selecao_pasta = gtk_application_window_new(app);
    janela_selecao_pasta = GTK_WIDGET(gtk_builder_get_object(builder, ID_JANELA_SELECAO_PASTA));

    selecionador = GTK_FILE_CHOOSER_BUTTON(gtk_builder_get_object(builder, ID_SELECAO_PASTA));

    diretorio_label = GTK_LABEL(gtk_builder_get_object(builder, ID_DIRETORIO_SELECIONADO));
    gtk_label_set_text(diretorio_label, diretorio_selecionado);

    gtk_widget_show_all(janela_selecao_pasta);
}
