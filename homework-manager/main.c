#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void newSchedule ();
void displaySchedule ();

int main (void) {
    while (1 == 1) {

        int input = startMenu();
        if (input == 1) {
            // create a new schedule
            newSchedule();
        } else if (input == 2) {
            // display existing shedules, give option to view them
            displaySchedule();
        } else if (input == 3) {
            puts("Bye for now.");
            return 0;
        }

    }
}

void newSchedule () {
    // get start and end dates
    Date start = getDate("Start");

    // build assignment array and get end date
    Date end;
    double incSize = getIncSize();
    AssignmentList hwArray = buildAssnArray(&end, incSize);

    // create new folder for this schedule
    StringWrapper dirName = makeSchedDir();

    // create new text file for each day
    makeDayFiles(dirName, start, end);

    // write "[assignment name]: [blocks]" for each assignment done that day
    writeDayFiles(start, end, incSize, hwArray, dirName);

    // free dynamically allocated memory
    free((void*)hwArray.loc);

}

void displaySchedule () {
    // ask which schedule the user wants to see
    StringWrapper folderSelection = getSchedule();

    // print out schedule to terminal (formatted)
    showSchedule(folderSelection);
}