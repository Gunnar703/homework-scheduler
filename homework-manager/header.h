#ifndef HEADER_H_
#define HEADER_H_

#define MAX_DIRNAME_LENGTH 20

// Type Definitions
typedef struct {
    int month;
    int day;
    int year;
} Date;

typedef struct {
    char name[255];
    Date dueDate;
    int numBlocks;
} Assignment;

typedef struct {
    Assignment * loc;
    int length;
} AssignmentList;

typedef struct {
    char name[1024];
} StringWrapper;

// Array Functions
int * blocksPerDay (Date startDate, Date endDate, double blockSize);
AssignmentList buildAssnArray (Date * endDate, double incSize);
AssignmentList sortHwList (AssignmentList hwArray);

// Date Handling
int afterDate (Date date1, Date date2);
int daysBetween (Date date1, Date date2);
Date dateAfterNDays (Date date, int daysAfter);

// File IO
StringWrapper makeSchedDir (void);
void makeDayFiles (StringWrapper schedDir, Date start, Date end);
void writeDayFiles (Date start, Date end, double incSize, AssignmentList hwArray, StringWrapper dirName);

// User Input
int startMenu (void);
Date getDate(char* dateType);
double getIncSize (void);

// Display
StringWrapper getSchedule (void);
int showSchedule (StringWrapper folder);

#endif