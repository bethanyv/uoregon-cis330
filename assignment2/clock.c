#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "clock.h"

void initClock(ClockType *clock) {
  /*8 for height. 6 for length of each line(including null byte of string)*/
  clock->zero = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->zero[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->zero[0] = "/---\\";
  clock->zero[1] = "|   |";
  clock->zero[2] = "|   |";
  clock->zero[3] = "|   |";
  clock->zero[4] = "|   |";
  clock->zero[5] = "|   |";
  clock->zero[6] = "|   |";
  clock->zero[7] = "\\___/";

  clock->one = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->one[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->one[0] = " /|  ";
  clock->one[1] = "  |  ";
  clock->one[2] = "  |  ";
  clock->one[3] = "  |  ";
  clock->one[4] = "  |  ";
  clock->one[5] = "  |  ";
  clock->one[6] = "  |  ";
  clock->one[7] = " --- ";

  clock->two = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->two[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->two[0] = " /'\\ ";
  clock->two[1] = "   \\ ";
  clock->two[2] = "   | ";
  clock->two[3] = "  /  ";
  clock->two[4] = " /   ";
  clock->two[5] = "|    ";
  clock->two[6] = "|    ";
  clock->two[7] = " --- ";

  clock->three = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->three[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->three[0] = "----\\";
  clock->three[1] = "    |";
  clock->three[2] = "   / ";
  clock->three[3] = "  -  ";
  clock->three[4] = "   \\ ";
  clock->three[5] = "    |";
  clock->three[6] = "    |";
  clock->three[7] = "----/";

  clock->four = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->four[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->four[0] = "|   |";
  clock->four[1] = "|   |";
  clock->four[2] = "\\   |";
  clock->four[3] = " ---|";
  clock->four[4] = "    |";
  clock->four[5] = "    |";
  clock->four[6] = "    |";
  clock->four[7] = "    |";

  clock->five = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->five[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->five = {
      "-----",
      "|    ",
      "|    ",
      "\\___ ",
      "    |",
      "    |",
      "    |",
      "\\___/"
  }

  clock->six = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->six[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->six = {
      "/---\\",
      "|    ",
      "|    ",
      "|---\\",
      "|   |",
      "|   |",
      "|   |",
      "\\___/"
  }

  clock->seven = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->seven[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->seven = {
      "/---\\",
      "    |",
      "    |",
      "    /",
      " --- ",
      "  /  ",
      " /   ",
      "/    "
  }

  clock->eight = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->eight[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->eight = {
      "/---\\",
      "|   |",
      "|   |",
      "|___|",
      "|   |",
      "|   |",
      "|   |",
      "\\___/"
  }

  clock->nine = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->nine[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->nine = {
      "/---\\",
      "|   |",
      "|   |",
      "\\___|",
      "    |",
      "    |",
      "    |",
      "\\___/"
  }


}

void printClock(const time_t cur_time, const ClockType *clock) {

}

void cleanClock(ClockType *clock) {
  for(int i = 0; i < 8; i++) {
    free(clock->zero[i]);
    free(clock->one[i]);
    free(clock->two[i]);
    free(clock->three[i]);
    free(clock->four[i]);
    free(clock->five[i]);
    free(clock->six[i]);
    free(clock->seven[i]);
    free(clock->eight[i]);
    free(clock->nine[i]);
  }
  free(clock);
}

int main(int argc, char** argv) 
{
  struct ClockType myclock;
  initClock(&myclock);

  cleanClock(&myclock);
  return 0;
}
