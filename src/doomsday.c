#include <math.h>
#include "dayOfWeek.h"
#include "doomsday.h"

int getDayOfWeek(int day, int month, int year) {
    int dayOfWeek = 0;
    int doomsday = getDoomsday(year);

    int difference = day - getMonthAnchorDay(month, year);
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
    int anchor = getCenturyAnchorDay(year);

    return (a + b + c + anchor) % 7;     // sum

    /*if (lastDigits % 2 != 0) {*/
        /*lastDigits += 11;*/
    /*}*/

    /*lastDigits /= 2;*/

    /*if (lastDigits % 2 != 0) {*/
        /*lastDigits += 11;*/
    /*}*/

    /*lastDigits = 7 - (lastDigits % 7);*/

}

int isLeapYear(int year) {
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
