#ifndef GENERIC_H_
#define GENERIC_H_

#include <stdint.h>
#include <stdio.h>
//BOOL
#define BOOL uint8_t
#define TRUE 1
#define FALSE 0

void clearbuffer(){
    while(getc(stdin) != '\n'){}
}

#endif