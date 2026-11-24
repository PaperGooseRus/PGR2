#include <stdio.h>

#include <gtk/gtk.h> //!< ПОДКЛЮЧАЕТСЯ ПРИ СБОРКЕ ЧЕРЕЗ pkg-config files gtk4

static void activate(GtkApplication *_application, gpointer user_data) {
    (void)user_data;

    printf("Start activate");

    GtkWidget *window_ = gtk_application_window_new(_application);
    gtk_window_set_title(GTK_WINDOW(window_), "PaperGooseRus");
    gtk_window_set_default_size(GTK_WINDOW(window_), 1920, 1080);
    gtk_window_present(GTK_WINDOW(window_));
}

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
