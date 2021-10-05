#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE* data = fopen("data.csv", "r");
    
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
    int* iUsia = (int*)malloc(asize * sizeof(int));
    
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

            //Usia
            tbuff = strtok(NULL, ";");
            iUsia[pos] = (int)strtol(tbuff, NULL, 10);
            agemax = iUsia[pos] > agemax?iUsia[pos]:agemax;
            agemin = agemin < iUsia[pos]?agemin:iUsia[pos];
        }
        pos++;
    }

    int rangesize = agemax - agemin + 1;

    int* agechart = (int*)calloc(rangesize, sizeof(int));

    for(int i = 0; i < asize; i++){
        agechart[iUsia[i] - agemin]++;
    }

    //printf("min age: %d, max age: %d, chart size: %d\n", agemin, agemax, rangesize);

    for(int i = 0; i < rangesize; i++){
        printf("%d: %d\n", agemin + i, agechart[i]);
    }

    free(sNIP);
    free(sNama);
    free(iUsia);
    
    getc(stdin); //press any key...

    return fclose(data);
}
