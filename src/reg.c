#include "reg.h"

static int dataSort(char** nip, char** nama, char* gender, char** gol, int* current_size,  //main array
                     char newnip[20], char newname[50], char newgender, char newgol[5])     //new data container
{ //sort by NIP
    BOOL is_greater;
    int strdiff;
    for(int i = 0; i < *current_size; i++){
        strdiff = strcmp(newnip, nip[i]);
        if(strdiff > 0){
            continue;
        }
        else if(strdiff < 0){
            return i + 1;
        }
        else if(strdiff == 0){
            printf("NIP yang persis sama ditemukan pada database!");
            return -1;
        }
    }
}

void dataPrint(char** nip, char** nama, char* gender, char** gol, int* current_size){
    for(int i = 0; i < *current_size; i++){
        printf("%2d. %20s %50s %c %3s\n", i + 1, nip[i], nama[i], gender[i], gol[i]);
    }
}

void addData(char** nip, char** nama, char* gender, char** gol, int* current_size){
    //new data container
    char nipctr[20];
    char namactr[50];
    char genderctr[4]; //fgets newline workaround
    char golctr[5];

    int newdatapos;

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
        printf("%-*s%-20s%-7s%-s\n", strlen(namactr)>4?strlen(namactr)+1:5, "Nama", "NIP", "Gender", "Golongan");
        printf("%-*s%-20s%-7c%s\n\n", strlen(namactr)>4?strlen(namactr)+1:5, namactr, nipctr, genderctr[0], golctr);

        printf("Apakah data sudah benar? [y/n]: ");
        verfresp = getc(stdin);
        if(verfresp == 'y'){
            inputloop = FALSE;
        }
        else{
            clearbuffer();
        }

        newdatapos = dataSort(nip, nama, gender, gol, current_size, nipctr, namactr, genderctr[0], golctr);
        printf("Posisi data baru: %d", newdatapos);
    }
}
