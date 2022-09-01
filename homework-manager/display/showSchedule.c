#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../header.h"

int showSchedule (StringWrapper folder) {

    FILE * fp;

    int day = 0;

    // get start date
    FILE * date;
    char dateFilePath[100];
    sprintf(dateFilePath, "output/%s/date.txt", folder.name);
    Date start = { 1, 1, 2001 };
    if ((date = fopen(dateFilePath, "r")) != NULL) {
        fscanf(date, "%d-%d-%d", &start.month, &start.day, &start.year);
        fclose(date);
        // for debugging - printf("Date: %d-%d-%d\n", start.month, start.day, start.year);
    } else {
        printf("Error reading date file. Defaulting start date to Jan 1, 2001.\n");
    }
    
    while (1 == 1) {
        char fnBuffer[100];
        sprintf(fnBuffer, "output/%s/%i.txt", folder.name, day);

        if ((fp = fopen(fnBuffer, "r")) != NULL) {
            // read the file info
            struct stat st;
            if (stat(fnBuffer, &st) == -1) {
                printf("There was an error reading the schedule files.");
            }

            // write info to stdout
            Date currDay = dateAfterNDays(start, day);
            printf("------( %d-%d-%d )------\n", currDay.month, currDay.day, currDay.year);

            char assnName[255];
            double numHours;

            while (fscanf(fp, "%s%lf", assnName, &numHours) != EOF) {
                for (int i = 0; i < 255; i++) {
                    if (assnName[i] == '\\') assnName[i] = ' ';
                }

                printf("   %s: %.2lf\n", assnName, numHours);
            }
            printf("\n");
            
            fclose(fp);
        } else {
            return 1;
        }

        day++;
    }
    
}