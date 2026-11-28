#include "gui/activate.h"

/**
 * \brief   АКТИВАЦИИ ЧЕРЕЗ КОЛБЭКИ И ЗАПУСК ПРИЛОЖЕНИЯ
 * \param   argc - КОЛИЧЕСТВО ПАРАМЕТРОВ ЗАПУСКА
 * \param   argv - ЗНАЧЕНИЯ ПАРАМЕТРОВ ЗАПУСКА В ВИДЕ СТРОК
 * \return  status - КОД ЗАВЕРШЕНИЯ РАБОТЫ ПРИЛОЖЕНИЯ GTK4
 */
int main(int argc, char *argv[]) {
    int status = 0x00;

    // СОЗДАНИЕ ПРИЛОЖЕНИЯ GTK4 СО СВОИМ ИДЕНТИФИКАТОРОМ ЧТОБЫ ОНО РАБОТАЛО НЕЗАВИСИМО С ДРУГИМИ ПИРЛОЖЕНИЯМИ
    GtkApplication *application_ = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);

    // СОЕДИНЕНИЕ ПРИЛОЖЕНИЯ GTK4 С ФУНКЦИЯМИ КОЛБЭКОВ
    g_signal_connect(application_, "activate", G_CALLBACK(activate), NULL);

    // ЗАПУСК САМОГО ПРИЛОЖЕНИЯ GTK4 И ОЖИДАНИЕ КОДА ЗАВЕРШЕНИЯ ПРИЛОЖЕНИЯ
    status = g_application_run(G_APPLICATION(application_), argc, argv);

    g_object_unref(application_);

    return status;
}
