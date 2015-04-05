#ifndef _doomsday_h
#define _doomsday_h

#define START_OF_GREGORIAN_CALENDER 1582

int getDayOfWeek(int day, int month, int year);
int getDoomsday(int year);
int isLeapYear(int year);
int getMonthAnchorDay(int month, int year);
int getCenturyAnchorDay(int year);

#endif
