#ifndef CLOCK_H_
#define CLOCK_H_

typedef struct {
	// 2D character arrays for each number for ascii art
	char** zero;
	char** one;
	char** two;
	char** three;
	char** four;
	char** five;
	char** six;
	char** seven;
	char** eight;
	char** nine;
	char** colon;
} ClockType;

// Initialize the clock data structure 
void initClock(ClockType *clock); // Matrix of numbers here

// Print an ASCII clock showing cur_time as the time 
void printClock(const time_t cur_time, const ClockType *clock);

// Free up any dynamically allocated memory in the clock
void cleanClock(ClockType *clock);

#endif /* CLOCK_H_ */