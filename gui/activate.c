#include "activate.h"

void activate(GtkApplication *_application, gpointer user_data) {
    (void)user_data;

    printf("Start activate");

    GtkWidget *window_ = gtk_application_window_new(_application);
    gtk_window_set_title(GTK_WINDOW(window_), "PaperGooseRus");
    gtk_window_set_default_size(GTK_WINDOW(window_), 1920, 1080);
    gtk_window_present(GTK_WINDOW(window_));
}
