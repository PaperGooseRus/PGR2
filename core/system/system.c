#include "system.h"

int system_run(const char *command, const char *log_file) {
    if (command == NULL || log_file == NULL) {
        return -1;
    }

    // Открываем файл для добавления результатов.
    FILE *file = fopen(log_file, "ab");

    if (file == NULL) {
        return -1;
    }

    // Записываем выполняемую команду.
    fprintf(file, "\r\n================================\r\n");
    fprintf(file, "COMMAND: %s\r\n", command);
    fprintf(file, "================================\r\n");

    // Запускаем CMD и получаем его вывод.
    FILE *pipe = _popen(command, "rb");

    if (pipe == NULL) {
        fclose(file);

        return -1;
    }

    // Читаем результат выполнения.
    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), pipe)) > 0) {
        if (fwrite(buffer, 1, bytes_read, file) != bytes_read) {
            _pclose(pipe);
            fclose(file);

            return -1;
        }
    }

    // Завершаем процесс.
    int exit_code = _pclose(pipe);

    fprintf(file, "\r\nEXIT CODE: %d\r\n", exit_code);

    fclose(file);

    return exit_code;
}