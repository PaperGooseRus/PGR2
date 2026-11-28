#include "tabe1.h"
#include "table.h"
#include "system.h"

void check_environment(void) {

    system_run(
        "gcc --version 2>&1",
        "data/system_log.txt"
    );

    system_run(
        "g++ --version 2>&1",
        "data/system_log.txt"
    );
}

GtkWidget* create_filling_tab1(void) {
    // СОДЕРЖАНИЕ ТАБЛИЦЫ
    const char* colums[] = {
        "ИНСТРУМЕНТ",
        "ВЕРСИЯ",
        "ПУИТ",
        "ВКЛЮЧЕНИЕ В PATH"
    };

    GtkWidget *table_ = table_create(colums, G_N_ELEMENTS(colums));

    check_environment();

    // ДОБАВЛЕНИЕ ДАННЫХ
    const char *row1_[] = {
        "GCC",
        "16.2.0",
        "C:/msys64",
        "TRUE"
    };
    
    const char *row2_[] = {
        "G++",
        "16.2.0",
        "C:/msys64",
        "TRUE"
    };

    table_add_row(table_, row1_);
    table_add_row(table_, row2_);

    return table_;
}