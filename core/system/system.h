#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>

/**
 * \brief   ВЫПОЛНЕНИЕ КОМАНДЫ CMD
 * \param   command  - КОМАНДА Windows CMD
 * \param   log_file - ФАЙЛ ДЛЯ ЗАПИСИ РЕЗУЛЬТАТА
 * \return  Возвращает код завершения команды. -1 означает ошибку запуска или записи.
 */
int system_run(const char *command, const char *log_file);

#endif // SYSTEM_H