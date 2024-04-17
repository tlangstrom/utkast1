#ifndef CALC_FREQUENCY
#define CALC_FREQUENCY

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    int character;
    int frequency;
} charFrequency;

charFrequency *calc_frequency(FILE *frequency_file_p);

#endif