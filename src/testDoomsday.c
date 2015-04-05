#include <stdio.h>
#include <assert.h>
#include "dayOfWeek.h"
#include "doomsday.h"
#include "tests.h"
#include "testDoomsday.h"

void testDoomsday() {
    testIsLeapYear();
    testGetDoomsday();
    testGetDayOfWeek();
}

void testIsLeapYear() {
    checkIsLeapYear(1582, FALSE);
    checkIsLeapYear(1999, FALSE);
    checkIsLeapYear(2000, TRUE);
    checkIsLeapYear(2001, FALSE);
    checkIsLeapYear(2004, TRUE);
}

void testGetDoomsday() {
    checkGetDoomsday(2000, TUESDAY);
    checkGetDoomsday(1998, SATURDAY);
    checkGetDoomsday(1997, FRIDAY);
    checkGetDoomsday(1996, THURSDAY);
    checkGetDoomsday(1995, TUESDAY);
    checkGetDoomsday(1985, THURSDAY);
    checkGetDoomsday(1850, THURSDAY);
    checkGetDoomsday(1610, SUNDAY);
    checkGetDoomsday(1601, WEDNESDAY);
    checkGetDoomsday(1600, TUESDAY);
}

void testGetDayOfWeek() {
    checkGetDayOfWeek(1, 1, 2000,  SATURDAY);
    checkGetDayOfWeek(1, 1, 2001,  MONDAY);
    checkGetDayOfWeek(5, 10, 1996, SATURDAY);
}

void checkIsLeapYear(int year, int expected) {
    int actual = isLeapYear(year);
    char *message;

    if (actual == expected) {
        asprintf(&message, "isLeapYear: %d -> %d", year, actual);
        statusOK(message);
    } else {
        asprintf(&message, "isLeapYear: %d -> %d expecting %d", year,
                actual, expected);
        statusFailed(message);
    }
}

void checkGetDoomsday(int year, int expected) {
    int actual = getDoomsday(year);
    char *message;

    if (actual == expected) {
        asprintf(&message, "getDoomsday: %d -> %d", year, actual);
        statusOK(message);
    } else {
        asprintf(&message, "getDoomsday: %d -> %d expecting %d", year,
                actual, expected);
        statusFailed(message);
    }
}

void checkGetDayOfWeek(int day, int month, int year, int expected) {
    int actual = getDayOfWeek(day, month, year);
    char *message;

    if (actual == expected) {
        asprintf(&message, "getDayOfWeek: %d %d %d -> %d", day, month,
                year, actual);
        statusOK(message);
    } else {
        asprintf(&message, "getDayOfWeek: %d %d %d -> %d expecting %d",
                day, month, year, actual, expected);
        statusFailed(message);
    }
}
