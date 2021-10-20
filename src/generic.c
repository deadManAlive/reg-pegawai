#include "generic.h"

void clearbuffer(){
    while(getc(stdin) != '\n'){}
}

void freestringsarr(char** arrstr, int size){
    for(int i = 0; i < size; i++){
        free(arrstr[i]);
    }
    free(arrstr);
}
