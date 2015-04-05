#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dayOfWeek.h"
#include "doomsday.h"
#include "tests.h"

int main(int argc, char *argv[]) {
    int day = 0;
    int month = 0;
    int year = 0;

    if (argc == 2) {
        if (strcmp(argv[1], "-t") == EQUAL) {
            runTests();
        } else {
            displayUsage();
        }
    } else if (argc == 3) {
        if (strcmp(argv[1], "-l") == EQUAL) {
            year = atoi(argv[2]);
            printf("%d is ", year);
            if (!isLeapYear(year))
                printf("not ");
            printf("a leap year.\n");
        } else if (strcmp(argv[1], "-d") == EQUAL) {
            year = atoi(argv[2]);
            printf("The doomsday for %d is %s.\n", year, getDayName(getDoomsday(year)));
        } else {
            displayUsage();
        }
    } else if (argc == 4) {
        day = atoi(argv[1]);
        month = atoi(argv[2]);
        year = atoi(argv[3]);

        printf("%d %d %d\n", day, month, year);
        printf("%s\n", getDayName(getDayOfWeek(day, month, year)));
    } else {
        displayUsage();
    }

    return EXIT_SUCCESS;
}

char *getDayName(int day) {
    switch (day) {
        case 0:
            return "Tuesday";
            break;
        case 1:
            return "Wednesday";
            break;
        case 2:
            return "Thursday";
            break;
        case 3:
            return "Friday";
            break;
        case 4:
            return "Saturday";
            break;
        case 5:
            return "Sunday";
            break;
        case 6:
            return "Monday";
            break;
        default:
            return NULL;
    }
}

void displayUsage() {
    printf("usage: dayofweek (<flag> [yyyy]) | (<dd> <mm> <yyyy>)\n");
    printf("flags\n");
    printf("-t\t run tests.\n");
    printf("-l\t check if a given year is a leap year or not.\n");
    printf("-d\t calculate the doomsday of a specified year.\n\n");
    printf("examples\n");
    printf("dayofweek -t\n");
    printf("dayofweek -l 2000\n");
    printf("dayofweek -d 2000\n");
    printf("dayofweek 01 01 2001\n\n");
}
