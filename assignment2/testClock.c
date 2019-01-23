#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "clock.h"
#include "clock.c"

int main(int argc, char** argv) 
{
  ClockType myclock;
  initClock(&myclock);

  cleanClock(&myclock);
  return 0;
}
