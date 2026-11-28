#include "activate.h"
#include "tabe1.h"

static void create_page(GtkWidget *notebook_, char *title_, GtkWidget *filling_) {
    GtkWidget *title_label_ = gtk_label_new(title_);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook_), filling_, title_label_);
}

static GtkWidget *create_notebook(void) {
    GtkWidget *notebook_ = gtk_notebook_new();

    // ПЕРВАЯ ВКЛАДКА
    create_page(notebook_, "ИНФОРМАЦИЯ О СИСТЕМЕ", create_filling_tab1());

    // ВТОРАЯ ВКЛАДКА
    // СОЗДАНИЕ СОДЕРЖИМОГО ВТОРОЙ ВКЛАДКИ
    GtkWidget *filling_tab2_ = gtk_label_new("СОДЕРЖИМОЕ ВТОРОЙ ВКЛАДКИ");
    create_page(notebook_, "ИНФОРМАЦИЯ О СИСТЕМЕ", filling_tab2_);

    // ...
    // СОЗДАНИЕ СОДЕРЖИМОГО ... ВКЛАДКИ

    return notebook_;
}

void activate(GtkApplication *_application, gpointer user_data) {
    (void)user_data;

    // СОЗДАНИЯ ГЛАВНОГО ОКНА ПРИЛОЖЕНИЯ
    GtkWidget *window_ = gtk_application_window_new(_application);
    // ПЕРВОНАЧАЛЬНАЯ НАСТРОЙКА ОКНА
    gtk_window_set_title(GTK_WINDOW(window_), "PaperGooseRus");
    gtk_window_set_default_size(GTK_WINDOW(window_), 1920, 1080);

    // ДОБАВЛЕНИЕ ВКЛАДОК
    gtk_window_set_child(GTK_WINDOW(window_), create_notebook());

    // ОТОБРАЖЕНИЕ ОКНА
    gtk_window_present(GTK_WINDOW(window_));
}
