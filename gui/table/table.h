
#ifndef TABLE_H
#define TABLE_H

#include <gtk/gtk.h>

/*
 * Создание таблицы.
 *
 * column_names - массив названий столбцов.
 * n_columns    - количество столбцов.
 *
 * Возвращает GtkWidget* (GtkGrid).
 */
GtkWidget *table_create(const char *const column_names[], guint n_columns);

/*
 * Добавление строки данных.
 *
 * table  - таблица, созданная через table_create().
 * values - массив значений для каждого столбца.
 *
 * Возвращает TRUE при успешном добавлении.
 */
gboolean table_add_row(GtkWidget *table, const char *const values[]);

#endif // TABLE_H
