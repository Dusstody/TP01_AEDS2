//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#include "JanelaIndiceInvertido.h"

void destroyJanelaIndiceInvertido(GtkWidget *widget, gpointer data) {
    gtk_widget_destroy(widget);
}

void inicializaJanelaIndiceInvertido(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkTreeView *treeview;
    GtkBuilder *builder;

    builder = gtk_builder_new_from_file(ARQUIVO_JANELA_INDICE_INVERTIDO);
    gtk_builder_add_callback_symbols(
                builder,
                "destroyJanelaIndiceInvertido", G_CALLBACK(destroyJanelaIndiceInvertido),
                NULL
            );
    gtk_builder_connect_signals(builder, NULL);

    window = gtk_application_window_new(app);
    window = GTK_WIDGET(gtk_builder_get_object(builder, ID_JANELA_INDICE_INVERTIDO));

    treeview = GTK_TREE_VIEW(gtk_builder_get_object(builder, ID_TREE_VIEW));

    gtk_widget_show_all(window);
}
