#ifndef GENERIC_H_
#define GENERIC_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//BOOL
#define BOOL uint8_t
#define TRUE 1
#define FALSE 0

//funcs
void clearbuffer();
void freestringsarr(char**, int);

#endif
