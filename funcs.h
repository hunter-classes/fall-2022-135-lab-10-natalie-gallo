#pragma once

void printTime(Time time);

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);

Time addMinutes(Time time0, int min);

std::string printMovie(Movie mv);
std::string getTimeSlot(TimeSlot ts);
