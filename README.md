# DayOfWeek

Small program that calculates the day of the week for a given date. For example, this project was created on the 30th of March 2015 (30/03/2015) which is a Monday.

The algorithm used is based off John Conway's Doomsday Rule which exploits the knowledge that the Gregorian calender moves in cycles of 400 years. 

This program works specifically for Gregorian calenders however the algorithm can be easily adapted to work with Julian calenders as well. 

## Usage
    dayofweek (<flag> [yyyy]) | <dd> <mm> <yyyy>

    flags
    -t  run tests
    -l  check if a specified year is a leap year
    -d  calculate the doomsday for a specified year
