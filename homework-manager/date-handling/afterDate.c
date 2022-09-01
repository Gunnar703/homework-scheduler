#include "../header.h"

int afterDate (Date date1, Date date2) {
    return daysBetween(date1, date2) > 0 ? 1 : 0;
}