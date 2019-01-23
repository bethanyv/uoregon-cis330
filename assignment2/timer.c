#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "timer.h"
#include "clock.h"
#include "clock.c"
#include <unistd.h>

void initTimer(ClockType *clock, int minutes, int seconds) {
  int total_time = (minutes * 60) + seconds;

  while(total_time >= 0) {
    seconds = total_time % 60;
    minutes = (int) total_time / 60;

    char** to_print[5];

    int digit_one, digit_two, digit_three, digit_four;
    digit_two = minutes % 10;
    digit_one = (int) (minutes - digit_two) / 10;
    digit_four = seconds % 10;
    digit_three = (int) (seconds - digit_two) / 10;

    int numbers[4] = {digit_one, digit_two, digit_three, digit_four};

    for(int i = 0; i < 5; i++) {
      if(i == 2) {
        to_print[2] = clock->colon;
      }
      else if(numbers[i] == 0) {
        to_print[i] = clock->zero;
      }
      else if(numbers[i] == 1) {
        to_print[i] = clock->one;
      }
      else if(numbers[i] == 2) {
        to_print[i] = clock->two;
      }
      else if(numbers[i] == 3) {
        to_print[i] = clock->three;
      }
      else if(numbers[i] == 4) {
        to_print[i] = clock->four;
      }
      else if(numbers[i] == 5) {
        to_print[i] = clock->five;
      }
      else if(numbers[i] == 6) {
        to_print[i] = clock->six;
      }
      else if(numbers[i] == 7) {
        to_print[i] = clock->seven;
      }
      else if(numbers[i] == 8) {
        to_print[i] = clock->eight;
      }
      else if(numbers[i] == 9) {
        to_print[i] = clock->nine;
      }
    }

    // printf("%d", numbers[0]);
    // printf("%d", numbers[1]);
    // printf("%s", ":");
    // printf("%d", numbers[2]);
    // printf("%d", numbers[3]);
    // printf("\n");
    for(int i = 0; i < 8; i++) {
      printf("%s", to_print[0][i]);
      printf("%s", to_print[1][i]);
      printf("%s", to_print[2][i]);
      printf("%s", to_print[3][i]);
      printf("%s", to_print[4][i]);
      printf("\n");
    }
    total_time = total_time - 1;
    runTimer();
  }
}

void runTimer() { // sleep
  sleep(1);
}

void cleanTimer(ClockType  *clock) {
  cleanClock(clock);
}

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