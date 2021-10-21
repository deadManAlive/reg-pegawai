#include "generic.h"

void clearbuffer(){
    while(getc(stdin) != '\n'){}
}

void destroy(char** arrstr, int size){
    for(int i = 0; i < size; i++){
        free(arrstr[i]);
    }
    free(arrstr);
}

void dataPrint(char** nip, char** nama, char* gender, char** gol, int* current_size){
    for(int i = 0; i < *current_size; i++){
        printf("%2d. %20s %50s %c %3s\n", i + 1, nip[i], nama[i], gender[i], gol[i]);
    }
}
