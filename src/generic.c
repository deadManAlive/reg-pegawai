#include <string.h>
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
