#include <stdio.h>
#include "libLog.h"
#include <string.h>
//this is a test file of libLog.h
int main() {
    printf("Hello, from Logging.\n");

    struct log_file_struct main_file_log;

    strcpy(main_file_log.log_filename, "merhaba.txt");

    log_init(&main_file_log);


    strcpy(main_file_log.log_message, "logging started.\n");
    log_detailed(&main_file_log);

    return 0;
}



