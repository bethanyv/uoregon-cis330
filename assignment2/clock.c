#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "clock.h"

void initClock(ClockType *clock) {
  char **arr = (char **) malloc ( 10 * sizeof(char*));
}

void printClock(const time_t cur_time, const ClockType *clock) {

}

void cleanClock(ClockType *clock) {

}

int main(int argc, char** argv) 
{
  ClockType myclock;
  initClock(myclock);
  return 0;
}
