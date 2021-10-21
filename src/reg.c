#include "reg.h"

void addData(char** nip, char** nama, char* gender, char** gol, int* current_size){
    //new data container
    char nipctr[20];
    char namactr[50];
    char genderctr[4]; //fgets newline workaround
    char golctr[5];

    bool inputloop = true;
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
            int icsize = ++(*current_size);

            char* tnip = realloc(*nip, icsize);
            if(tnip){ // != NULL
                *nip = tnip;
                nip[icsize - 1] = malloc(20);
                strcpy(nip[icsize - 1], nipctr);
            }

            char* tnama = realloc(*nama, icsize);
            if(tnama){
                *nama = tnama;
                nama[icsize - 1] = malloc(50);
                strcpy(nama[icsize - 1], namactr);
            }

            char* tgender = realloc(gender, icsize);
            if(tgender){
                gender = tgender;
                gender[icsize - 1] = genderctr[0];
            }

            char* tgol = realloc(*gol, 5 * icsize);
            if(tgol){
                *gol = tgol;
                gol[icsize - 1] = malloc(5);
                strcpy(gol[icsize - 1], golctr);
            }

            inputloop = false;
        }
        else{
            clearbuffer();
        }

    }
}
