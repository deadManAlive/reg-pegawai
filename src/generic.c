#include "generic.h"

void clearbuffer(void){
    while(getc(stdin) != '\n'){}
}

void destroy(char** arrstr, int size){
    for(int i = 0; i < size; i++){
        free(arrstr[i]);
    }
    free(arrstr);
}

void dataPrint(char** nip, char** nama, char* gender, char** gol, int* current_size){
    printf("No. %-20s%-50s%-7s%-s\n", "Nama", "NIP", "Gender", "Golongan");
    for(int i = 0; i < *current_size; i++){
        printf("%2d. %-20s%-50s%-7c%-s\n", i + 1, nip[i], nama[i], gender[i], gol[i]);
    }
}
