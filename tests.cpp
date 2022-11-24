#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include "funcs.h"
using namespace std;

TEST_CASE("TASK A"){
  Time time_1 = { 10, 30 };
  Time time_2 = { 13, 40 };
  Time time_3 = { 14, 20 };
  CHECK(minutesSinceMidnight(time_1) == 630);
  CHECK(minutesSinceMidnight(time_2) == 820);

  CHECK(minutesUntil(time_1, time_2) == 190);
  CHECK(minutesUntil(time_1, time_3) == 230);
}

TEST_CASE("TASK B"){
  Time time_1 = { 8, 10 };
  Time time_2 = { 10, 30 };

  Time time_test1 = addMinutes(time_1, 120);
  Time time_test2 = addMinutes(time_2, 73);

  CHECK(time_test1.h == 10);
  CHECK(time_test1.m == 10);

  CHECK(time_test2.h == 11);
  CHECK(time_test2.m == 43);
}

  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Us", THRILLER, 120};

  TimeSlot morning = {movie1, {9, 15}};  
  TimeSlot daytime = {movie2, {12, 15}}; 
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot night = {movie1, {19,25}};
  TimeSlot solo_booking = {movie3, {18, 41}};

TEST_CASE("TASK C"){ 
  CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
  CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
  CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");
  CHECK(getTimeSlot(night) == "Back to the Future COMEDY (116 min) [starts at 19:25, ends by 21:21]");
  CHECK(getTimeSlot(solo_booking) == "Us THRILLER (120 min) [starts at 18:41, ends by 20:41]");
}

TEST_CASE("TASK D"){
  TimeSlot scheduledMovie = scheduleAfter(daytime, movie2);

  CHECK(scheduledMovie.startTime.h >= 14);
  CHECK(scheduledMovie.startTime.m >= 29);

  scheduledMovie = scheduleAfter(morning, movie2);
  CHECK(scheduledMovie.startTime.h >= 11);
  CHECK(scheduledMovie.startTime.m >= 11);
}

TEST_CASE("TASK E"){
  TimeSlot overlap_ex = {movie3, {15, 15}};

  CHECK(timeOverlap(morning, overlap_ex) == 0);
  CHECK(timeOverlap(daytime, overlap_ex) == 0);
  CHECK(timeOverlap(evening, overlap_ex) == 1);
}
  
  

  
