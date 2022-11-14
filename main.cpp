#include <iostream>
#include <string>
using namespace std;
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include "funcs.h"

int main()
{
  //TASK A
  Time time_1 = { 10, 30 };
  Time time_2 = { 13, 40 };

  std::cout << "1: Minutes since Midnight -> " << minutesSinceMidnight(time_1) << std::endl;

  std::cout << "2: Minutes since Midnight -> " << minutesSinceMidnight(time_2) << std::endl;

  std::cout << "Interval between them is " << minutesUntil(time_1, time_2) << " minutes. \n";

  //TASK B
  Time time_3 = { 8, 10 };
  Time adjusted_time = addMinutes(time_3, 75);
  printTime(adjusted_time);
  cout << endl;

  //TASK C
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};

  TimeSlot morning = {movie1, {9, 15}};  
  TimeSlot daytime = {movie2, {12, 15}}; 
  TimeSlot evening = {movie2, {16, 45}};

  std::cout << getTimeSlot(morning) << endl;
  std::cout << getTimeSlot(daytime) << endl;
  std::cout << getTimeSlot(evening) << endl;
  //add two more slots
  
  return 0;
}

