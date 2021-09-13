//
// Created by duce on 12/09/2021.
//

#include "App.h"

gint startApp(int argc, char *argv[]) {
    GtkApplication *app;
    gint status;

    app = gtk_application_new("tp1.aeds2", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(inicializaJanelaPrincipal), NULL);
    status = g_application_run(app, argc, argv);

    g_object_unref(app);

    return status;
}
