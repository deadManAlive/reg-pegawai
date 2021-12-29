#ifndef REG_H_
#define REG_H_

#include "generic.h"
#include "linkedlist.h"
#include "historylist.h"

#include <string.h>

//Function to input data, add to array, and increment current data size
void rowquicksort(char** nip, char** nama, char* gender, char** gol, int low, int high);
void addData(char** nip, char** nama, char** gender, char** gol, int* current_size, ListNode** list, HNode* hist);
void removeData(char** nip, char** nama, char* gender, char** gol, int* current_size, ListNode** list, HNode* hist);
void dataPrint(char** nip, char** nama, char* gender, char** gol, int* current_size);

#endif
