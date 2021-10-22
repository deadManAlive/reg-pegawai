//main program
#include "reg.h"

int main(){
    //start of data parsing process
    FILE* data = fopen(DATABASE, "rw");
    
    if(data == NULL){
            printf("File data pegawai (data_pegawai.csv) tidak ditemukan!");
            return -1;
    }
    
    int size = 0;
    for(char c = getc(data); c!= EOF; c = getc(data)){
             size = (c == '\n')?size+1:size;
    }
    
    int asize = size - 1; //size without header
    
    //container construction
    char **sNIP = malloc(asize * sizeof(char*));
    char **sNama = malloc(asize * sizeof(char*));
    char *sGender = malloc(asize * sizeof(char));
    char **sGol = malloc(asize * sizeof(char*));

    for(int i = 0; i < asize; i++){
        sNIP[i] = (char*)malloc(20);
        sNama[i] = (char*)malloc(50);
        sGol[i] = (char*)malloc(5);
    }

    fseek(data, 0, SEEK_SET);
    
    char csv_line_ctr[100];
    
    int pos = 0;
    char gdrctr[2];
    while(fgets(csv_line_ctr, 100, data)){
        fscanf(data, "%[^\n]", csv_line_ctr);
        if(strcmp(csv_line_ctr, "\n") != 0){
            //NIP
            char* tbuff = strtok(csv_line_ctr, ";");
            strcpy(sNIP[pos], tbuff);

            //Nama
            tbuff = strtok(NULL, ";");
            strcpy(sNama[pos], tbuff);

            //Kelamin
            tbuff = strtok(NULL, ";");
            strcpy(gdrctr, tbuff);
            sGender[pos] = tbuff[0];

            //Golongan
            tbuff = strtok(NULL, ":");
            strcpy(sGol[pos], tbuff);
        }
        pos++;
    }
    //end of data parsing process

    //user interface loop
    bool inputloop = true;
    char inputopt;
    while(inputloop){
        //splash
        printf("Program Registrasi Pegawai\n");
        printf("~~MENU~~\n");
        printf("d. daftar\n");
        printf("c. lihat data\n");
        printf("x. keluar\n");
        printf("Masukkan input: ");

        inputopt = getchar();

        switch(inputopt){
            case 'd':
                getchar(); //eliminate \n
                addData(sNIP, sNama, sGender, sGol, &asize);
                break;
            case 'c':
                rowquicksort(sNIP, sNama, sGender, sGol, 0, asize - 1);
                dataPrint(sNIP, sNama, sGender, sGol, &asize);
                getchar(); //eliminate \n
                break;
            case 'x':
                printf("~~EXIT~~");
                inputloop = false;
                break;
            default:
                printf("Input tidak valid!\n");
        }
    }

    destroy(sNIP, asize);
    destroy(sNama, asize);
    destroy(sGol, asize);
    free(sGender);
    
    getc(stdin); //press any key...

    return fclose(data);
}
