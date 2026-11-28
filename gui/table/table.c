
#include "table.h"

typedef struct {
    guint n_columns;
    guint next_row;
} TableState;


/*
 * Создание одной ячейки.
 */
static GtkWidget *create_cell(const char *text) {
    GtkWidget *label = gtk_label_new(text ? text : "");

    gtk_label_set_xalign(GTK_LABEL(label), 0.0f);
    gtk_label_set_yalign(GTK_LABEL(label), 0.5f);

    gtk_label_set_wrap(GTK_LABEL(label), TRUE);
    gtk_label_set_selectable(GTK_LABEL(label), TRUE);

    gtk_widget_set_hexpand(label, TRUE);

    gtk_widget_set_margin_start(label, 8);
    gtk_widget_set_margin_end(label, 8);
    gtk_widget_set_margin_top(label, 6);
    gtk_widget_set_margin_bottom(label, 6);

    return label;
}


/*
 * Создание таблицы с заголовками.
 */
GtkWidget *table_create(const char *const column_names[], guint n_columns) {
    g_return_val_if_fail(column_names != NULL, NULL);
    g_return_val_if_fail(n_columns > 0, NULL);

    GtkWidget *grid = gtk_grid_new();

    gtk_grid_set_column_spacing(GTK_GRID(grid), 1);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 1);

    gtk_widget_set_hexpand(grid, TRUE);
    gtk_widget_add_css_class(grid, "view");

    // Создание заголовков.
    for (guint column = 0; column < n_columns; column++) {

        GtkWidget *header = create_cell(column_names[column]);

        gtk_widget_add_css_class(header, "heading");

        gtk_grid_attach(
            GTK_GRID(grid),
            header,
            column,
            0,
            1,
            1
        );
    }

    // Сохранение состояния таблицы.
    TableState *state = g_new0(TableState, 1);

    state->n_columns = n_columns;
    state->next_row = 1;

    g_object_set_data_full(
        G_OBJECT(grid),
        "table-state",
        state,
        g_free
    );

    return grid;
}


/*
 * Добавление строки.
 */
gboolean table_add_row(GtkWidget *table, const char *const values[]) {
    g_return_val_if_fail(GTK_IS_GRID(table), FALSE);
    g_return_val_if_fail(values != NULL, FALSE);

    TableState *state = g_object_get_data(
        G_OBJECT(table),
        "table-state"
    );

    g_return_val_if_fail(state != NULL, FALSE);

    for (guint column = 0;
         column < state->n_columns;
         column++) {

        GtkWidget *cell = create_cell(values[column]);

        gtk_grid_attach(
            GTK_GRID(table),
            cell,
            column,
            state->next_row,
            1,
            1
        );
    }

    state->next_row++;

    return TRUE;
}
