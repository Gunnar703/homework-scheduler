#include <stdio.h>
#include <stdlib.h>

double getIncSize (void) {
    double incSize;
    printf("\n\nIncrement Size: ");

    char str[10];
    fflush(stdin);
    fgets(str, 10, stdin);
    incSize = strtod(str, &str);

    // scanf("%lf", &incSize);

    return incSize;
}