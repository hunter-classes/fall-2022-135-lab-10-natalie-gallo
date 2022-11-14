#include <iostream>

int main()
{
  //TASK A
  Time time_1 = { 10, 30 };
  Time time_2 = { 13, 40 };

  std::cout << "1: Minutes since Midnight -> " << minutesSinceMidnight(time_1) << std::endl;

  std::cout << "2: Minutes since Midnight -> " << minutesSinceMidnight(time_2) << std::endl;

  std::cout << "Interval between them is " << minutesUntil(time_1, time_2) << " minutes. \n";

  //TASK B
  
  return 0;
}

