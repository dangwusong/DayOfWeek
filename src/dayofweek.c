#include <stdio.h>
#include <stdlib.h>
#include "doomsday.h"
#include "dayofweek.h"

int main(int argc, char *argv[]) {
    int day = 0;
    int month = 0;
    int year = 0;

    if (argc == 4) {
        day = atoi(argv[1]);
        month = atoi(argv[2]);
        year = atoi(argv[3]);
    } else {
        displayUsage();
    }

    printf("%d %d %d\n", day, month, year);
    printf("%s\n", getDayName(getDayOfWeek(day, month, year)));

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
    printf("usage: dayofweek <dd> <mm> <yyyy>\n");
}
