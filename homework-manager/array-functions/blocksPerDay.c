#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../header.h"

int* blocksPerDay (Date startDate, Date endDate, double blockSize) {
    int numDays = daysBetween(startDate, endDate);
    int* blocksPerDay = (int*)malloc(numDays * sizeof(int));

    for (int i = 0; i < numDays; i++) {
        double hoursAvailable;
        Date curr = dateAfterNDays(startDate, i);
        printf("Hours available for homework on %d-%d-%d: ", curr.month, curr.day, curr.year);
        char str[10];
        fgets(str, 10, stdin);
        hoursAvailable = strtod(str, &str);

        int blocksAvailable = floor(hoursAvailable / blockSize);
        blocksPerDay[i] = blocksAvailable;
    }

    return blocksPerDay;
}