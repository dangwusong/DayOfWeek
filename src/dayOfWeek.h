#ifndef _dayofweek_h
#define _dayofweek_h

#define TRUE 1
#define FALSE 0

#define EQUAL 0

#define SUNDAY   0
#define MONDAY   1
#define TUESDAY  2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY   5
#define SATURDAY 6

#define START_OF_GREGORIAN_CALENDER 1582

char *getDayName(int day);
void displayUsage(void);

#endif
