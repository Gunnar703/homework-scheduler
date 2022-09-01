#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../header.h"

AssignmentList sortHwList (AssignmentList hwArray) {
    int daysUntilDue[hwArray.length];
    Date datum = { 1, 1, 1900 };
    for (int i = 0; i < hwArray.length; i++) {
        daysUntilDue[i] = daysBetween(datum, hwArray.loc[i].dueDate);
    }

    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int i = 0; i < hwArray.length - 1; i++) {
            if (daysUntilDue[i + 1] < daysUntilDue[i]) {
                sorted = false;
                int dueAux = daysUntilDue[i];
                daysUntilDue[i] = daysUntilDue[i + 1];
                daysUntilDue[i + 1] = dueAux;

                Assignment hwAux = hwArray.loc[i];
                hwArray.loc[i] = hwArray.loc[i + 1];
                hwArray.loc[i + 1] = hwAux;
            }
        }
    }

    return hwArray;
}