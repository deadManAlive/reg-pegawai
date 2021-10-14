#ifndef REG_H_
#define REG_H_

#include "generic.h"
#include <string.h>

//Function to input data, add to array, and increment current data size
void addData(char** nip, char** nama, char* gender, char** gol, int* current_size){
    char nipctr[20];
    char namactr[50];
    char genderctr[4];
    char golctr[5];

    BOOL inputloop = TRUE;
    char verfresp;

    while(inputloop){
    //input phase
        printf("==REGISTRASI==\n");
        printf("Nama <Maks. 48 karakter termasuk spasi>                     : ");
        fgets(namactr, 50, stdin);
        namactr[strcspn(namactr, "\n")] = 0;
        printf("NIP <18 Angka>                                              : ");
        fgets(nipctr, 20, stdin);
        nipctr[strcspn(nipctr, "\n")] = 0;
        printf("Kelamin <L/P>                                               : ");
        fgets(genderctr, 4, stdin);
        genderctr[strcspn(genderctr, "\n")] = 0;
        printf("Golongan <format: X-Y dengan X (1,2,3,4) dan Y (A,B,C,D)>   : ");
        fgets(golctr, 5, stdin);
        golctr[strcspn(golctr, "\n")] = 0;

        printf("\n~~verifikasi~~\n");
        printf("%-*s%-20s%-7s%-s\n", strlen(namactr)>4?strlen(namactr):5, "Nama", "NIP", "Gender", "Golongan");
        printf("%-*s%-20s%-7c%s\n\n", strlen(namactr)>4?strlen(namactr):5, namactr, nipctr, genderctr[0], golctr);

        printf("Apakah data sudah benar? [y/n]: ");
        verfresp = getc(stdin);
        if(verfresp == 'y'){
            inputloop = FALSE;
        }
        else{
            clearbuffer();
        }
    }
}

#endif
