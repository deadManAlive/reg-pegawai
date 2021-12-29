#include <string.h>
#include <math.h>

#include <generic.h>

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
    //print consistent tab size on No.
    int tabsize = log10(*current_size) + 1;
    tabsize = tabsize>1?tabsize:2;
    tabsize++;

    //resize name column
    int nmax = 0;
    int ssize;
    for(int i = 0; i < *current_size; i++){
        ssize = strlen(nama[i]);
        nmax = ssize>nmax?ssize:nmax;
    }

    printf("%*s. %-20s%-*s%-8s%-s\n", tabsize, "No", "NIP", nmax + 1, "Nama", "Gender", "Golongan");
    for(int i = 0; i < *current_size; i++){
        printf("%*d. %-20s%-*s%-8c%-s\n", tabsize, i + 1, nip[i], nmax + 1, nama[i], gender[i], gol[i]);
    }
}

void banner(){

    #ifdef WIN32
    #define CLEAR "cls"
    #else
    #define CLEAR "clear"
    #endif

    system(CLEAR);
    printf("==========================\n");
    printf("PROGRAM PENCATATAN PEGAWAI\n");
    printf("==========================\n");
}
