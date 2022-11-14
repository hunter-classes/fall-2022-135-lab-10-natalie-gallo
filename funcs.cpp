#include <iostream>
#include "time.h"
#include "move.h"
#include "timeslot.h"


//LAB EXAMPLE FUNCTION

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}


//TASK A

int minutesSinceMidnight(Time time){
  //assign time.h and time.m to separate variables
  //multiply the value of h by 60 (min)
  //add ^ and value of m for total minutes since 0:00

  int hours = time.h;
  int minutes = time.m;

  hours = hours * 60;

  minutes = minutes + hours;

  return minutes;
}

int minutesUntil(Time earlier, Time later){
  //subtract later.h - earlier.h, then multiply difference by 60 (min)
  //subtract later.m - earlier.m and add difference to ^

  int hours = (later.h - earlier.h) * 60;

  int minutes = later.m - earlier.m;

  minutes = minutes + hours;

  return minutes;
}


Time addMinutes(Time time0, int min){
  int minutes = minutesSinceMidnight(time0);

  minutes = minutes + min;

  int hours = minutes / 60;

  minutes = minutes % 60;

  Time newTime;

  newTime.h = hours;
  newTime.m = minutes;

  return newTime;
}

