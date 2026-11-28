#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <gtk/gtk.h>

/**
 * \brief   КОЛБЭК АКТИВАЦИИ
 * \param   GtkApplication *_application - УКАЗАТЕЛЬ НА ПРИЛОЖЕНИЕ К КОТОРОМУ ОТНОСИТСЯ ДАННЫЙ КОЛБЭК
 * \param   gpointer user_data - ПЕРЕМЕННЫЕ ...
 * \return  NULL
 */
void activate(GtkApplication *_application, gpointer user_data);

#endif // ACTIVATE_H
