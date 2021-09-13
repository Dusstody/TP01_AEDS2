//
// Criado por:
// * Jeniffer Laila - 3896
// * Pedro Maia - 3878
// * Gabriel Batista Custodio - 3879
//

#include "JanelaBusca.h"

void *threadPreenchimento() {
    resultados = AutoFillTST(dicionario, (char*) entrada, indice);
}

void buscaTermoNaPatricia(GtkWidget *widget, gpointer data) {
    char *message;
    message = (char *)(malloc(sizeof(char) * 120));

    if (strlen(entrada) > 0) {
        busca(entrada, patricia, files.quantidade, files.nomesArq, files.idDocs);
        strcpy(message, "Busca concluída! Veja os resultados no terminal.");
    } else {
        strcpy(message, "Ao menos um caractere deve ser digitado!");
    }

    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(
            GTK_WINDOW(janela_busca), GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,
            "%s", message
    );

    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);

    free(message);
    gtk_entry_set_text(GTK_ENTRY(campo_pesquisa), "");

    strcpy(entrada, "");
}

GtkTreeModel* novoAutopreenchimento() {
    g_print("%s\n", entrada);

    GtkListStore *list;
    GtkTreeIter iter;

    int count;
    indice = (int*) malloc(sizeof (int));
    *indice = 0;

    const gint COLUNA = 0;

    list = gtk_list_store_new(1, G_TYPE_STRING);

    count = 0;
    while (entrada[count] != '\0') {
        ++count;
    }

    if (count >= MIN_LETRAS_ENTRADA) {
        printf("Começando busca\n");

        pthread_create(&thread_preenchimento, NULL, threadPreenchimento, NULL);
        pthread_join(thread_preenchimento, NULL);

        printf("Começando busca\n");

        *indice = (*indice > MAX_RESULTADOS_PREENCHIMENTO) ? MAX_RESULTADOS_PREENCHIMENTO : *indice;

        for (int i = 0; i < *indice; ++i) {
            g_print("%s\n", resultados[i]);
            gtk_list_store_append(list, &iter);
            gtk_list_store_set(list, &iter, COLUNA, (gchar*) resultados[i], -1);
        }
    }

    return GTK_TREE_MODEL(list);

}

void destroyJanelaBusca(GtkWidget *widget, gpointer data) {
    gtk_widget_destroy(widget);
}

void updatePesquisa(GtkWidget *widget, gpointer data) {
    entrada = gtk_entry_get_text(GTK_ENTRY(widget));

    GtkTreeModel *model;
    model = novoAutopreenchimento();

    gtk_entry_completion_set_model(completion, model);
    g_object_unref (model);
}

void inicializaJanelaBusca(GtkApplication *app, gpointer user_data) {
    GtkWidget *botao_busca;
    GtkTreeModel *completion_model;

    GtkBuilder *builder;
    builder = gtk_builder_new_from_file(ARQUIVO_JANELA_BUSCA);
    gtk_builder_add_callback_symbols(
                builder,
                "destroyJanelaBusca", G_CALLBACK(destroyJanelaBusca),
                "updatePesquisa", G_CALLBACK(updatePesquisa),
                "iniciarBuscaPatricia", G_CALLBACK(buscaTermoNaPatricia),
                NULL
            );
    gtk_builder_connect_signals(builder, NULL);
    janela_busca = gtk_application_window_new(app);
    janela_busca = GTK_WIDGET(gtk_builder_get_object(builder, ID_JANELA_BUSCA));

    campo_pesquisa = GTK_SEARCH_ENTRY(gtk_builder_get_object(builder, ID_PESQUISA_JANELA_BUSCA));

    completion = gtk_entry_completion_new();

    gtk_entry_set_completion(GTK_ENTRY(campo_pesquisa), completion);
    g_object_unref(completion);

    gtk_entry_completion_set_text_column(completion, 0);

    gtk_widget_show_all(janela_busca);
} // hospit