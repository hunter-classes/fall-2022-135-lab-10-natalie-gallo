#include <iostream>
#include <string>
using namespace std;
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include "funcs.h"


//LAB EXAMPLE FUNCTION

void printTime(Time time) {
  std::cout << time.h << ":" << time.m;
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

//TASK B

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

//TASK C

std::string printMovie(Movie mv){
  std::string movie_details;
  std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    movie_details =  mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
    return movie_details;
}

std::string getTimeSlot(TimeSlot ts){
  
  std::string movie_details = printMovie(ts.movie);
  
  movie_details +=  " [starts at ";

  //Replicating printTime function but I didnt want to change from void...
  Time movie_start = ts.startTime;
  std::string hours = std::to_string(movie_start.h);
  std::string minutes = std::to_string(movie_start.m);
  movie_details += hours + ":" + minutes;
  
  movie_details += ", ends by ";

  Movie movie_playing = ts.movie;

  int movie_length = movie_playing.duration; //in minutes

  Time end_time = addMinutes(ts.startTime, movie_length);

  hours = std::to_string(end_time.h);
  minutes = std::to_string(end_time.m);
  movie_details += hours + ":" + minutes;

  movie_details += "]";

  return movie_details;
}

//TASK D

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  Time newTime = addMinutes(ts.startTime, ts.movie.duration);
  TimeSlot newMovie;

  newMovie.movie = nextMovie;
  newMovie.startTime = newTime;

  return newMovie;
}

//TASK E

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  //use minutesUntil to check which ts is earlier
  //find how long the interval is btwn starttimes of each
  //if movie duration > interval^ -> they overlap
  int interval = minutesUntil(ts1.startTime, ts2.startTime);

  bool overlap = false;

  int movie_duration = ts1.movie.duration;

  if (movie_duration > interval){
    overlap = true;
  } else {
    overlap = false;
  }

  return overlap;
}
