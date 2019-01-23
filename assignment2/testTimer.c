#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "timer.h"

int main(int argc, char** argv) 
{
  ClockType myclock;
  initClock(&myclock);
  int min;
  int sec;

  printf("How long should the timer run (MM:SS)? ");
  scanf("%d:%d", &min, &sec);
  
  initTimer(&myclock, min, sec);

  cleanTimer(&myclock);
  return 0;
}