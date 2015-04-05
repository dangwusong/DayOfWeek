#ifndef _dayofweek_h
#define _dayofweek_h

#define TRUE 1
#define FALSE 0

#define EQUAL 0

#define TUESDAY  0
#define WEDNESDAY 1
#define THURSDAY 2
#define FRIDAY   3
#define SATURDAY 4
#define SUNDAY   5
#define MONDAY   6

#define START_OF_GREGORIAN_CALENDER 1582

char *getDayName(int day);
void displayUsage(void);

#endif
