#include <stdio.h>
#include "../header.h"

Date getDate(char* dateType) {
    // TODO: validate input
    char dateInput[11];
    printf("%s date (mm-dd-yyyy): ", dateType);
    fflush(stdin);
    fgets(dateInput, 11, stdin);

    Date date;
    sscanf(dateInput, "%2d-%2d-%4d", &date.month, &date.day, &date.year);

    return date;
}