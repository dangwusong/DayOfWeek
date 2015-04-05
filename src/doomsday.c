#include <math.h>
#include "dayOfWeek.h"
#include "doomsday.h"

int getDayOfWeek(int day, int month, int year) {
    int difference = day - getMonthAnchorDay(month, year);
    int dayOfWeek = (getDoomsday(year) + difference) % 7;

    if (dayOfWeek < 0)
        dayOfWeek += 7;

    return dayOfWeek;
}

int getDoomsday(int year) {
    int digits = year % 100;

    // calculations based off Conway's Doomsday algorithm
    int a = floor(digits / 12);          // floor of the quotient
    int b = digits % 12;                 // remainder
    int c = floor(b / 4);                // floot of quotient
    int d = getCenturyAnchorDay(year);
    return (a + b + c + d) % 7;
}

int isLeapYear(int year) {
    if (year < START_OF_GREGORIAN_CALENDER)
        return FALSE;
    return year % 4 == 0 || year % 400 == 0;
}

int getMonthAnchorDay(int month, int year) {
    int anchorDays[12] = {
        3,  // January
        28, // Febuary
        7,  // March
        4,  // April
        9,  // May
        6,  // June
        11, // July
        8,  // August
        5,  // September
        10, // October
        7,  // November
        12  // December
    };

    if (isLeapYear(year)) {
        anchorDays[0] = 4;
        anchorDays[1] = 29;
    }

    return anchorDays[month-1];
}

int getCenturyAnchorDay(int year) {
    year %= 400;
    if (year >= 0 && year <= 99)
        return TUESDAY;
    if (year >= 100 && year <= 199)
        return SUNDAY;
    if (year >= 200 && year <= 299)
        return FRIDAY;
    if (year >= 300 && year <= 399)
        return WEDNESDAY;
    return 0;
}
