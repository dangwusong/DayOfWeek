#include <stdio.h>
#include "tests.h"
#include "testDoomsday.h"

void runTests() {
    testDoomsday();
}

void statusOK(const char *string) {
    printf("[\033[32mpass\033[0m] %s\n", string);
}

void statusFailed(const char *string) {
    printf("[\033[31mfail\033[0m] %s\n", string);
}
