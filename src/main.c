//main program
#include <reg.h>
#include <stat.h>
#include <container.h>

#define DATABASE "data_pegawai.csv"

int main(){

    banner();

    //start of data parsing process
    FILE* data = fopen(DATABASE, "r");
    
    if(data == NULL){
            printf("File data pegawai (data_pegawai.csv) tidak ditemukan!");
            return -1;
    }
    
    int size = 0;
    for(char c = getc(data); c!= EOF; c = getc(data)){
             size = (c == '\n')?size+1:size;
    }
    
    int asize = size - 1; //size without header

    STR *sNIP = malloc(asize * sizeof(STR));
    STR *sNama = malloc(asize * sizeof(STR));
    char *sGender = malloc(asize * sizeof(char));
    STR *sGol = malloc(asize * sizeof(STR));

    for(int i = 0; i < asize; i++){
        sNIP[i] = malloc(20);
        sNama[i] = malloc(50);
        sGol[i] = malloc(5);
    }

    fseek(data, 0, SEEK_SET);
    
    char csv_line_ctr[100];
    
    int pos = 0;
    char gdrctr[2];
    while(fgets(csv_line_ctr, 100, data) != NULL){
        fscanf(data, "%[^\n]", csv_line_ctr);

        //trailing newline check
        if(strcmp(csv_line_ctr, "\n") == 0){
            continue;
        }

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
            tbuff = strtok(NULL, ";");
            strcpy(sGol[pos], tbuff);
        }
        pos++;
    }
    //end of data parsing process

    //array to container (linked list)
    ListNode* mainContainer = malloc(sizeof(ListNode));
    *mainContainer = constructList(sNIP[0], sNama[0], sGender[0], sGol[0]);

    for(int i = 1; i < asize; i++){
        insert(&mainContainer, sNIP[i], sNama[i], sGender[i], sGol[i]);
    }
    //end of array to container

    //user interface loop
    bool inputloop = true;
    char inputopt;
    while(inputloop){
        //splash
        printf("\nProgram Registrasi Pegawai\n");
        printf("~~MENU~~\n");
        printf("d. daftar\n");
        printf("r. hapus data\n");
        printf("v. lihat data\n");
        printf("s. lihat statistik\n");
        printf("x. keluar\n");
        printf("Masukkan input: ");

        inputopt = getchar();

        switch(inputopt){
            case 'd':
                getchar(); //eliminate \n
                addData(sNIP, sNama, sGender, sGol, &asize);
                break;
            case 'r':
                getchar();
                removeData(sNIP, sNama, sGender, sGol, &asize);
                break;
            case 'v':
                rowquicksort(sNIP, sNama, sGender, sGol, 0, asize - 1);
                dataPrint(sNIP, sNama, sGender, sGol, &asize);
                getchar(); //eliminate \n
                break;
            case 's':
                viewStat(sNIP, sNama, sGender, sGol, asize);
                getchar();
                break;
            case 'x':
                printf("~~EXIT~~");
                inputloop = false;
                break;
            default:
                printf("Input tidak valid!\n");
        }
    }

    //end read file
    fclose(data);

    //file write proc.
    data = fopen(DATABASE, "w");

    fputs("NIP;Nama;Kelamin;Golongan\n", data); //header
    char linectr[100];
    for(int i = 0; i < asize; i++){
        fprintf(data, "%s;%s;%c;%s\n", sNIP[i], sNama[i], sGender[i], sGol[i]);
    }

    fclose(data);
    
    getchar(); //press any key...

    return 0;
}
