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
  cout << "\n\nTASK A \n\n";
  Time time_1 = { 10, 30 };
  Time time_2 = { 13, 40 };

  std::cout << "1: Minutes since Midnight -> " << minutesSinceMidnight(time_1) << std::endl;

  std::cout << "2: Minutes since Midnight -> " << minutesSinceMidnight(time_2) << std::endl;

  std::cout << "Interval between them is " << minutesUntil(time_1, time_2) << " minutes. \n";

  //TASK B
  cout << "\n\nTASK B \n\n";
  Time time_3 = { 8, 10 };
  Time adjusted_time = addMinutes(time_3, 75);
  cout << "8:10 + 75 min = ";
  printTime(adjusted_time);
  cout << endl;

  //TASK C
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Us", THRILLER, 120};

  TimeSlot morning = {movie1, {9, 15}};  
  TimeSlot daytime = {movie2, {12, 15}}; 
  TimeSlot evening = {movie2, {16, 45}};

  //MY OWN SLOTS
  TimeSlot night = {movie1, {19,25}};
  TimeSlot solo_booking = {movie3, {18, 41}};
  
  cout << "\n\nTASK C \n\n";
  std::cout << getTimeSlot(morning) << endl;
  std::cout << getTimeSlot(daytime) << endl;
  std::cout << getTimeSlot(evening) << endl;
  //my own
  std::cout << getTimeSlot(night) << endl;
  std::cout << getTimeSlot(solo_booking) << endl;

  //TASK D
  TimeSlot scheduledMovie = scheduleAfter(daytime, movie2);
  cout << "\n\nTASK D \n\n";
  std::cout << getTimeSlot(daytime) << std::endl;
  std::cout << getTimeSlot(scheduledMovie) << std::endl;

  //TASK E
  cout << "\n\nTASK E \n\n";
  TimeSlot overlap_ex = {movie3, {15, 15}};
  bool overlap = timeOverlap(daytime, overlap_ex);
  cout << "'Black Panther' at 12:15 and 'Us' at 3:15 (15:15). Overlap?\n";
  cout << std::boolalpha << overlap << endl;
  
  return 0;
}

