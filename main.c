#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE* data = fopen("data_pegawai.csv", "r");
    
    if(data == NULL){
            printf("Err: file database tidak dapat ditemukan!");
            return -1;
    }
    
    int size = 0;
    for(char c = getc(data); c!= EOF; c = getc(data)){
             size = (c == '\n')?size+1:size;
    }
    
    int asize = size - 1; //exclude header
    
    char (*sNIP)[20] = malloc(asize * sizeof(*sNIP));
    char (*sNama)[50] = malloc(asize * sizeof(*sNama));
    char (*sGender)[2] = malloc(asize * sizeof(*sGender));
    char (*sGol)[4] = malloc(asize * sizeof(*sGol));
    
    fseek(data, 0, SEEK_SET);
    
    char csv_line_ctr[100];
    int agemin = 100;
    int agemax = 0;
    
    int pos = 0;
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
            strcpy(sGender[pos], tbuff);

            //Golongan
            tbuff = strtok(NULL, ":");
            strcpy(sGol[pos], tbuff);
        }
        pos++;
    }

    for(int i = 0; i < asize; i++){
        printf("%s %s %s %s\n", sNIP[i], sNama[i], sGender[i], sGol[i]);
    }

    free(sNIP);
    free(sNama);
    free(sGender);
    free(sGol);
    
    getc(stdin); //press any key...

    return fclose(data);
}
