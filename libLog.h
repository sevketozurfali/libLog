//
// Created by sevket on 29.09.2020.
//
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifndef LIBLOG_MAIN_H
#define LIBLOG_MAIN_H

#endif //LIBLOG_MAIN_H

struct log_file_struct{
    char log_filename[1024];
    FILE *file;
    char log_message[4096];
};

void log_init(struct log_file_struct *logFileStruct);
void log_simple(struct log_file_struct *logFileStruct);
//void log_detailed(struct log_file_struct *logFileStruct);


void log_init(struct log_file_struct *logFileStruct) {
    printf("log_init...\n");

    logFileStruct->file = fopen(logFileStruct->log_filename, "w+");
    fclose(logFileStruct->file);
}

void log_simple(struct log_file_struct *logFileStruct){
    printf("log_simple...\n");
    logFileStruct->file = fopen(logFileStruct->log_filename, "a");

    fputs(logFileStruct->log_message, logFileStruct->file);
    strcpy(logFileStruct->log_message, "");

    fclose(logFileStruct->file);
}

void log_detailed(struct log_file_struct *logFileStruct){
    printf("log_detailed...\n");

    logFileStruct->file = fopen(logFileStruct->log_filename, "a");

    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

    char *log_message[4096];
    strcat(log_message, time_str);
    strcat(log_message, " | ");
    strcat(log_message, logFileStruct->log_message);

    fputs(log_message, logFileStruct->file);

    strcpy(log_message, "");


    fclose(logFileStruct->file);
}