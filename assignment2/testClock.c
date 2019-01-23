#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "clock.h"

int main(int argc, char** argv) 
{
  ClockType myclock;
  initClock(&myclock);
  
  time_t now = time(NULL);
  printClock(now, &myclock);

  cleanClock(&myclock);
  return 0;
}