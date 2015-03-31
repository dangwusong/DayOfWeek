#include <math.h>
#include "doomsday.h"

int getDayOfWeek(int day, int month, int year) {
    int dayOfWeek = 0;
    int doomsday = getDoomsday(year);

    int difference = day - getAnchorDay(month, year);
    dayOfWeek = (doomsday + difference) % 7;

    while (dayOfWeek < 0) {
        dayOfWeek += 7;
    }

    return dayOfWeek;
}

int getDoomsday(int year) {
    int lastDigits = year % 100;    // last 2 digits of the year

    int a = floor(lastDigits / 12); // floor of the quotient
    int b = lastDigits % 12;        // remainder
    int c = floor(b / 4);           // floot of quotient

    return a + b + c;               // sum
}

int isLeapYear(int year) {
    return year % 4 == 0 || year % 400 == 0;
}

int getAnchorDay(int month, int year) {
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
