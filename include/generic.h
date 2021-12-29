#ifndef GENERIC_H_
#define GENERIC_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//BOOL
typedef enum _boolenum {
    true = 1,
    false = 0,
    drift = -1 //in case undefined bool is necessary
} bool;

//funcs
void clearbuffer(void);
void destroy(char** arrstr, int size);
void dataPrint(char** nip, char** nama, char* gender, char** gol, int* current_size);
void banner();
#endif
