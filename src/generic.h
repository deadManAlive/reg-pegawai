#ifndef GENERIC_H_
#define GENERIC_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DATABASE "data_pegawai.csv"

//BOOL
typedef enum _boolenum {
    true = 1,
    false = 0,
    drift = -1
} bool;

//funcs
void clearbuffer();
void destroy(char**, int);
void dataPrint(char**, char**, char*, char**, int*);

#endif
