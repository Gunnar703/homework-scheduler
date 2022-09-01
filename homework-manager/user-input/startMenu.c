#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../header.h"

int startMenu (void) {
    int input;
    puts("1. New Schedule\n2. View Existing Schedule\n3. Exit Program");

    char inStr[2];
    fgets(inStr, 2, stdin);
    input = strtol(inStr, &inStr, 10);

    if (input != 1 && input != 2 && input != 3) {
        puts("Error.");
        printf("\n\n");
        input = startMenu();
    }

    return input;
}