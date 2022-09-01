#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "../header.h"

StringWrapper makeSchedDir (void) { // creates a directory to house .txt files for each day in the current schedule, returns name of directory

    char outputDir[MAX_DIRNAME_LENGTH + 11] = "output/";
    char schedName[21];
    printf("\n\nEnter schedule name (up to 20 characters, including spaces): ");
    fflush(stdin);
    fgets(schedName, 21, stdin);

    for (int i = 0; i < sizeof(schedName)/sizeof(char); i++) {
        if (schedName[i] == ' ') schedName[i] = '\\' ;
    }

    strcat(outputDir, schedName); // eq. to outputDir += schedName in JS

    struct stat st = {0};
    //check if dir exists
    if (stat(outputDir, &st) != -1) {
        //if it does, ask for a new name
        printf("Error. A schedule by that name already exists.\n");
        printf("\n\nEnter schedule name (up to 20 characters, including spaces): ");
        fflush(stdin);
        fgets(schedName, 21, stdin);

        for (int i = 0; i < sizeof(schedName)/sizeof(char); i++) {
            if (schedName[i] == ' ') schedName[i] = '\\' ;
        }
    } else {
        //if it doesn't, create it
        mkdir(outputDir, 0700);
    }

    StringWrapper fileName;

    strcpy(fileName.name, outputDir);

    return fileName;
}