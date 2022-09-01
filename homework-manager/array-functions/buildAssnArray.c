#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "../header.h"

AssignmentList buildAssnArray (Date * endDate, double incSize) {
    AssignmentList hwArray;
    hwArray.length = 0;
    hwArray.loc  = (Assignment*)malloc(1 * sizeof(Assignment));

    int stop = 0;
    int i = 0;
    while (stop == 0) {
        Assignment assn;

        printf("\n\nAssignment %d:\n", i + 1);
        printf("Assignment Name: ");
        fflush(stdin);
        fgets(assn.name, 255, stdin);
        
        char spaceDelim = '\\';

        for (int i = 0; i < sizeof(assn.name)/sizeof(char); i++) {
            if (assn.name[i] == ' ') {
                assn.name[i] = spaceDelim;
            }
        }

        assn.dueDate = getDate("Due");

        double numHours;
        printf("Estimated time to complete (hrs): ");

        char str[3];
        fflush(stdin);
        fgets(str, 3, stdin);
        numHours = strtod(str, &str);

        assn.numBlocks = (int)ceil(numHours / incSize);

        if (hwArray.length == 0) {
            hwArray.loc[0] = assn;
            hwArray.length = 1;
        } else {
            hwArray.loc = (Assignment*)realloc( (void*)hwArray.loc, (hwArray.length + 1) * sizeof(Assignment) );
            hwArray.length++;
            hwArray.loc[i] = assn;
        }
        i++;

        printf("Done? (1 for yes, 0 for no) ");
        scanf("%d", &stop);
    }

    hwArray = sortHwList(hwArray);

    endDate->day = hwArray.loc[hwArray.length - 1].dueDate.day;
    endDate->month = hwArray.loc[hwArray.length - 1].dueDate.month;
    endDate->year = hwArray.loc[hwArray.length - 1].dueDate.year;

    return hwArray;
}