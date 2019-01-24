#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "timer.h"
#include "clock.h"
#include "clock.c"
#include <unistd.h>

void initTimer(ClockType *clock, int minutes, int seconds) {
  // the total time calculation
  int total_time = (minutes * 60) + seconds;

  // while there is still time left, keep going and finding the next digits
  while(total_time >= 0) {
    // calculate the seconds and minutes
    seconds = total_time % 60; 
    minutes = (int) total_time / 60;

    // create a 2D array for holding the digits we want to print
    char** to_print[6];

    // grab individual digits with modulo and division
    int digit_one, digit_two, digit_three, digit_four;  
    digit_two = minutes % 10;
    digit_one = (int) (minutes - digit_two) / 10;
    digit_four = seconds % 10;
    digit_three = (int) (seconds - digit_two) / 10;

    // new array to iterate through to find what ascii digit we want
    int numbers[] = {digit_one, digit_two, digit_three, digit_four};

    // for each of the four digits, find what ascii digit we want and assign
    // it to the 2D array we initialized up above (to_print)
    for(int i = 0; i < 5; i++) {
      if(numbers[i] == 0) {
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
    // for the 8 lines (height) of the ascii characters, print
    // the piece of each digit/colon so it prints horizontally
    for(int i = 0; i < 8; i++) {
      printf("%s", to_print[0][i]);
      printf("%s", to_print[1][i]);
      printf("%s", clock->colon[i]);
      printf("%s", to_print[2][i]);
      printf("%s", to_print[3][i]);
      printf("\n");
    }
    // subtract from total time for it to continue
    total_time = total_time - 1;
    // call run timer to sleep
    runTimer();
  }
}

void runTimer() { 
  // sleep for one second
  sleep(1);
}

void cleanTimer(ClockType  *clock) {
  // free the data initalized when creating a clock
  cleanClock(clock);
}