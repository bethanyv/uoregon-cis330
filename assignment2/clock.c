#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "clock.h"

void initClock(ClockType *clock) {
  /*8 for height. 6 for length of each line(including null byte of string)*/
  clock->zero = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->zero[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->zero = {
      " --- ",
      "|   |",
      "|   |",
      "|   |",
      "|   |",
      "|   |",
      "|   |",
      " --- "
  }

  clock->one = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->one[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->one = {
      " /|  ",
      "  |  ",
      "  |  ",
      "  |  ",
      "  |  ",
      "  |  ",
      "  |  ",
      " --- "
  }

  clock->two = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->two[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->two = {
      " /'\\  ",
      "   \\ ",
      "   | ",
      "  /  ",
      " /   ",
      "|    ",
      "|    ",
      " --- "
  }

  clock->three = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->three[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->three = {
      "----\\",
      "    |",
      "   / ",
      "  -  ",
      "   \\ ",
      "    |",
      "    |",
      "----/"
  }

  clock->four = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->four[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->four = {
      "|   |",
      "|   |",
      "\\   |",
      " ---|",
      "    |",
      "    |",
      "    |",
      "    |"
  }

  clock->five = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->five[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->six = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->six[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->seven = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->seven[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->eight = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->eight[i] = (char *) malloc(6 * sizeof(char))
  }
  clock->nine = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->nine[i] = (char *) malloc(6 * sizeof(char))
  }


}

void printClock(const time_t cur_time, const ClockType *clock) {

}

void cleanClock(ClockType *clock) {

}

int main(int argc, char** argv) 
{
  struct ClockType myclock;
  initClock(myclock);
  return 0;
}
