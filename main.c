#include <stdio.h>

#include "gui/activate.h"

int main(int argc, char *argv[]) {
    int status = 0x00;

    printf("Tasrt main");

    GtkApplication *application_ =
        gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(application_, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(application_), argc, argv);

    g_object_unref(application_);

    return status;
}
