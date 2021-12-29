#include <reg.h>
#include <math.h>

#define ALLOCERR printf("!!Error in Allocation!!\n");

bool exitTest(const char* input){
    if(strlen(input) == 1 && input[0] == 'X'){
        return true;
    }
    else{
        return false;
    }
}

void rowswap(char** nip, char** nama, char* gender, char** gol, int posA, int posB){
    char tnip[20];
    char tnama[50];
    char tgender;
    char tgol[5];

    strcpy(tnip, nip[posA]);
    strcpy(nip[posA], nip[posB]);
    strcpy(nip[posB], tnip);

    strcpy(tnama, nama[posA]);
    strcpy(nama[posA], nama[posB]);
    strcpy(nama[posB], tnama);

    tgender = gender[posA];
    gender[posA] = gender[posB];
    gender[posB] = tgender;

    strcpy(tgol, gol[posA]);
    strcpy(gol[posA], gol[posB]);
    strcpy(gol[posB], tgol);
}

int partition(char** nip, char** nama, char* gender, char** gol, int low, int high){
    char pivot[20];
    strcpy(pivot, nip[high]);

    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(strcmp(pivot, nip[j]) > 0){
            i++;
            rowswap(nip, nama, gender, gol, i, j);
        }
    }
    rowswap(nip, nama, gender, gol, i + 1, high);
    return (i + 1);
}

void rowquicksort(char** nip, char** nama, char* gender, char** gol, int low, int high){
    if(low < high){
        int par = partition(nip, nama, gender, gol, low, high);
        rowquicksort(nip, nama, gender, gol, low, par - 1);
        rowquicksort(nip, nama, gender, gol, par + 1, high);
    }
}

int getData(char** nip, int size, const char* query){
    for(int i = 0; i < size; i++){
        if(strcmp(query, nip[i]) == 0){
            return i; //found
        }
    }
    return -1; //not found
}


void addData(char** nip, char** nama, char* gender, char** gol, int* current_size, ListNode** list, HNode* hist){
    //new data container
    char nipctr[20];
    char namactr[50];
    char genderctr[4]; //fgets newline workaround
    char golctr[5];

    bool inputloop = true;
    char verfresp;

    while(inputloop){
        //input phase
        printf("\n==REGISTRASI==\n");
        printf("(Masukkan 'X' untuk membatalkan)\n");

        printf("Nama <Maks. 48 karakter termasuk spasi>                     : ");
        fgets(namactr, 50, stdin);
        namactr[strcspn(namactr, "\n")] = 0;

        if(exitTest(namactr) == true){
            printf("Proses dibatalkan...\n");
            return;
        }

        printf("NIP <18 Angka>                                              : ");
        fgets(nipctr, 20, stdin);
        nipctr[strcspn(nipctr, "\n")] = 0;

        //nip check mech.
        if(exitTest(nipctr) == true){
            printf("Proses dibatalkan...\n");
            return;
        }
        if(strlen(nipctr) != 18){
            printf("NIP tidak valid!\n");
            continue;
        }
        if(getData(nip, *current_size, nipctr) != -1){
            printf("NIP telah terdaftar dalam data!\n");
            continue;
        }

        printf("Kelamin <L/P>                                               : ");
        fgets(genderctr, 4, stdin);
        genderctr[strcspn(genderctr, "\n")] = 0;

        //gender check
        if(genderctr[0] == 'X'){
            printf("Proses dibatalkan...\n");
            return;
        }
        if(genderctr[0] != 'L' && genderctr[0] != 'P'){
            printf("Kelamin tidak valid! (L/P)\n");
            continue;
        }

        printf("Golongan <format: X-Y dengan X (1,2,3,4) dan Y (A,B,C,D)>   : ");
        fgets(golctr, 5, stdin);
        golctr[strcspn(golctr, "\n")] = 0;

        //gol cek
        if(exitTest(golctr) == true){
            printf("Proses dibatalkan...\n");
            return;
        }
        switch(golctr[0]){
            case '1':
            case '2':
            case '3':
            case '4':
                break;
            default:
                printf("Golongan tidak valid! (0)\n");
                continue;
        }
        if(golctr[1] != '-'){
            printf("Golongan tidak valid! (1)\n");
        }
        switch(golctr[2]){
            case 'A':
            case 'B':
            case 'C':
            case 'D':
                break;
            case 'E':
                if(golctr[0] != '4'){
                    printf("Golongan tidak valid! (3)\n");
                    continue;
                }
            default:
                printf("Golongan tidak valid! (2)\n");
                continue;
        }

        //verf. phase
        printf("\n~~verifikasi~~\n");
        printf("%-*s%-20s%-7s%-s\n", strlen(namactr)>4?strlen(namactr)+1:5, "Nama", "NIP", "Gender", "Golongan");
        printf("%-*s%-20s%-7c%s\n\n", strlen(namactr)>4?strlen(namactr)+1:5, namactr, nipctr, genderctr[0], golctr);

        printf("Apakah data sudah benar? [y/n/x]: ");
        verfresp = getc(stdin);
        if(verfresp == 'y'){
            int nsize = ++(*current_size);

            char* tnip = realloc(*nip, nsize);
            if(tnip){ // != NULL
                *nip = tnip;
                nip[nsize - 1] = malloc(20);
                strcpy(nip[nsize - 1], nipctr);
            }
            else{
                ALLOCERR
                return;
            }

            
            char* tnama = realloc(*nama, nsize);
            if(tnama){
                *nama = tnama;
                nama[nsize - 1] = malloc(50);
                strcpy(nama[nsize - 1], namactr);
            }
            else{
                ALLOCERR
                return;
            }

            printf("\n===IN===\n"); //test
            char* tgender = realloc(gender, nsize);
            printf("\n===TEST===\n"); //test
            if(tgender){
                gender = tgender;
                gender[nsize - 1] = genderctr[0];
            }
            else{
                ALLOCERR
                return;
            }

            char* tgol = realloc(*gol, 5 * nsize);
            if(tgol){
                *gol = tgol;
                gol[nsize - 1] = malloc(5);
                strcpy(gol[nsize - 1], golctr);
            }
            else{
                ALLOCERR
                return;
            }
            printf("\n===OUT===\n"); //test

            inputloop = false;

            insert(list, nipctr, namactr, genderctr[0], golctr);
            newAction(hist, ADD_DATA, nipctr);
        }
        else if(verfresp == 'x'){
            printf("Input data baru dibatalkan...\n");
            inputloop = false;
            clearbuffer();
        }
        else{
            clearbuffer();
        }
    }
}

void removeData(char** nip, char** nama, char* gender, char** gol, int* current_size, ListNode** list, HNode* hist){
    if(*current_size == 0){
        printf("Database kosong!");
        return;
    }
    
    char nipctr[20];
    
    printf("\n==UNREGISTRASI==\n");

    bool inputloop = true;
    char verfresp[5];

    while(inputloop){
        printf("Masukkan NIP ('X' untuk membatalkan): ");
        fgets(nipctr, 20, stdin);
        nipctr[strcspn(nipctr, "\n")] = 0;

        if(exitTest(nipctr) == true){
            printf("Proses dibatalkan...\n");
            return;
        }

        int pos = getData(nip, *current_size, nipctr);

        if(pos == -1){
            printf("Data tidak ditemukan!\n");
            continue;
        }

        printf("!!Program akan menghapus pegawai dengan data berikut dari database!!\n");
        printf("%-*s%-20s%-7s%-s\n", strlen(nama[pos])>4?strlen(nama[pos])+1:5, "Nama", "NIP", "Gender", "Golongan");
        printf("%-*s%-20s%-7c%s\n", strlen(nama[pos])>4?strlen(nama[pos])+1:5, nama[pos], nipctr, gender[pos], gol[pos]);
        printf("!!Ketik 'YA' untuk melanjutkan: ");

        fgets(verfresp, 5, stdin);
        verfresp[strcspn(verfresp, "\n")] = 0;

        if(strcmp(verfresp, "YA") != 0){
            return;
        }

        //element removal proc.
        int nsize = --(*current_size);
        for(int i = pos; i < nsize; i++){
            rowswap(nip, nama, gender, gol, i, i + 1);
        }

        //realoc to smaller array
        char* tnip = realloc(*nip, nsize);
        if(tnip){ // != NULL
            *nip = tnip;
        }
        else{
            ALLOCERR
            return;
        }

        char* tnama = realloc(*nama, nsize);
        if(tnama){
            *nama = tnama;
        }
        else{
            ALLOCERR
            return;
        }

        char* tgender = realloc(gender, nsize);
        if(tgender){
            gender = tgender;
        }
        else{
            ALLOCERR
            return;
        }

        char* tgol = realloc(*gol, 5 * nsize);
        if(tgol){
            *gol = tgol;
        }
        else{
            ALLOCERR
            return;
        }

        inputloop = false;

        delete(list, nipctr);
        newAction(hist, REM_DATA, nipctr);
    }
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