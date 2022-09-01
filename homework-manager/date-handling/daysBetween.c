#include "../header.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int daysBetween (Date date1, Date date2) {
    int year1 = date1.year - 1900;
    int month1 = date1.month - 1;
    int day1 = date1.day;

    struct tm t1 = { .tm_mon = month1, .tm_mday = day1, .tm_year = year1};

    int year2 = date2.year - 1900;
    int month2 = date2.month - 1;
    int day2 = date2.day;

    struct tm t2 = { .tm_mon = month2, .tm_mday = day2, .tm_year = year2};

    time_t time1 = mktime(&t1);
    time_t time2 = mktime(&t2);

    double secsBetween = difftime(time2, time1);

    int dayDiff = floor(secsBetween/86400);

    return dayDiff;
}