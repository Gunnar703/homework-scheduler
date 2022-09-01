#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "../header.h"

void makeDayFiles (StringWrapper schedDir, Date start, Date end) {

    char outputFile[35];
    strcpy(outputFile, schedDir.name);

    for (int i = 0; i < daysBetween(start, end); i++) {
        char fileName[31 + 8];

        sprintf(fileName, "%s/%d.txt", outputFile, i);

        FILE * fp;
        fp = fopen(fileName, "w");
        fclose(fp);
    }

}