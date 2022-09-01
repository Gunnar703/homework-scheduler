#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../header.h"

StringWrapper getSchedule (void) {
    DIR *d;
    struct dirent* dir;
    char path[] = "output";
    d = opendir(path);

    if (d == NULL) {
        perror("opendir");
        StringWrapper nullReturn = {"ERROR"};
        return nullReturn;
    }

    int numFiles = 1;
    StringWrapper * listOfFiles = (StringWrapper*)malloc(numFiles * sizeof(StringWrapper));

    int iterations = 0;

    while ((dir = readdir(d)) != NULL) {
        iterations++;
        struct stat st;

        if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;

        if (fstatat(dirfd(d), dir->d_name, &st, 0) < 0) {
            perror(dir->d_name);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (numFiles == 1) {
                strcpy(listOfFiles[0].name, dir -> d_name);
                numFiles++;
            } else {
                listOfFiles = (StringWrapper*)realloc((void*)listOfFiles, numFiles * sizeof(StringWrapper));
                strcpy(listOfFiles[numFiles-1].name, dir -> d_name);
                numFiles++;
            }

        }

    }

    StringWrapper file;

    if (iterations > 0) {
        printf("Available Schedules: \n");
        for (int i = 0; i < numFiles - 1; i++) {
            printf("(%d) %s\n", i + 1,  listOfFiles[i].name);
        }

        printf("\nSchedule to view: ");

        char buffer[4];
        fflush(stdin);
        fgets(buffer, 4, stdin);

        int fileIdx = strtol(buffer, &buffer, 10) - 1;

        strcpy(file.name, listOfFiles[fileIdx].name);

    } else {
        printf("No schedules have been created yet.\n");
    }

    free((void*)listOfFiles);
    closedir(d);
    return file;
}