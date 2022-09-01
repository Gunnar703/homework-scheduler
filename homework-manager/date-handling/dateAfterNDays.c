#include <stdio.h>
#include <time.h>
#include "../header.h"

Date dateAfterNDays (Date date, int daysAfter) {

    int y = date.year, m = date.month, d = date.day;
    struct tm t = { .tm_year = y - 1900, .tm_mon = m - 1, .tm_mday = d };

    t.tm_mday += daysAfter;
    mktime(&t);

    Date dateAfter = { t.tm_mon + 1, t.tm_mday, t.tm_year + 1900 };

    return dateAfter;

}