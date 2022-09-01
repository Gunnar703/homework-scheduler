#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../header.h"

void writeDayFiles (Date start, Date end, double incSize, AssignmentList hwArray, StringWrapper dirName) {

    int * availableBlocks = blocksPerDay(start, end, incSize);

    int day = 0;
    int assn = 0;

    // store the start date of the current schedule
    FILE * date;
    char dateFilePath[100];
    sprintf(dateFilePath, "%s/date.txt", dirName.name);
    date = fopen(dateFilePath, "w");

    fprintf(date, "%d-%d-%d", start.month, start.day, start.year);
    fclose(date);

    while (day < daysBetween(start, end) && assn < hwArray.length) {

        char fileToWrite[40];
        sprintf(fileToWrite, "%s/%d.txt", dirName.name, day);
        FILE * fp;

        int compTime = hwArray.loc[ assn ].numBlocks;

        if (availableBlocks[day] == 0) {

            day++;

        } else if (availableBlocks[day] > compTime) {

            fp = fopen(fileToWrite, "a");

            // write [hwArray.loc[assn].name]: [compTime] to file "output/[dirName.name]/[day]"
            fprintf(fp, "%s%f", hwArray.loc[assn].name, availableBlocks[day] * incSize);
            fclose(fp);

            availableBlocks[day] -= compTime;
            hwArray.loc[assn].numBlocks = 0;
            assn++;

        } else if (availableBlocks[day] < compTime) {

            fp = fopen(fileToWrite, "a");

            // write [hwArray.loc[assn].name]: [availableBlocks[day]] to file "output/[dirName.name]/[day]"
            fprintf(fp, "%s%f", hwArray.loc[assn].name, availableBlocks[day] * incSize);
            fclose(fp);

            hwArray.loc[assn].numBlocks -= availableBlocks[day];
            availableBlocks[day] = 0;
            day++;
        } else {

            fp = fopen(fileToWrite, "a");

            // write [hwArray.loc[i].name]: [compTime] to file "output/[dirName.name]/[day]"
            fprintf(fp, "%s%f", hwArray.loc[assn].name, availableBlocks[day] * incSize);
            fclose(fp);
            // subtract [comptime] form [availableBlocks[day]]
            availableBlocks[day] = 0;
            hwArray.loc[assn].numBlocks = 0;
            assn++;
            day++;
        }
        
    }
    free((void*)availableBlocks);
}