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

    return notebook_;
}

/**
 * \brief   ОСНОВНАЯ ФУНКЦИЯ СОЗДАНИЯ СОДЕРЖИМОГО ОКНА
 */
void activate(GtkApplication *_application, gpointer user_data) {
    if (_application == NULL) {
        return;
    }

    (void)user_data;

    // СОЗДАНИЯ ГЛАВНОГО ОКНА ПРИЛОЖЕНИЯ
    GtkWidget *window_ = gtk_application_window_new(_application);
    if (window_ == NULL) {
        return;
    }

    // ПЕРВОНАЧАЛЬНАЯ НАСТРОЙКА ОКНА
    gtk_window_set_title(GTK_WINDOW(window_), "PaperGooseRus");
    gtk_window_set_default_size(GTK_WINDOW(window_), 1920, 1080);

    // СОЗДАНИЕ ГЛАВНОГО NOTEBOOK ПРИЛОЖЕНИЯ
    GtkWidget *notebook_ = create_notebook();
    if (notebook_ == NULL) {
        return;
    }

    gtk_window_set_child(GTK_WINDOW(window_), notebook_);

    // ОТОБРАЖЕНИЕ ОКНА
    gtk_window_present(GTK_WINDOW(window_));
}
