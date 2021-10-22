#ifndef REG_H_
#define REG_H_

#include "generic.h"
#include <string.h>

//Function to input data, add to array, and increment current data size
void rowquicksort(char** nip, char** nama, char* gender, char** gol, int low, int high);
void addData(char** nip, char** nama, char* gender, char** gol, int* current_size);

#endif
