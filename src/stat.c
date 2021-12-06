#include <stat.h>

void viewStat(char** nip, char** nama, char* gender, char** gol, int size){
    int nmale = 0; //jumlah L
    int nfmle = 0; //jumlah P
    int golmat[4][5] = {0}; //gol x sub-gol -> [1234]x[ABCDE]

    for(int i = 0; i < size; i++){
        //gender
        if(gender[i] == 'L'){
            nmale++;
        }
        else{
            nfmle++;
        }

        //gol
        golmat[gol[i][0] - '1'][gol[i][2] - 'A']++;
    }

    printf("\n==STAT==\n");
    printf("Jumlah pria   : %d\n", nmale);
    printf("Jumlah wanita : %d\n", nfmle);

    printf("\n~~Tabel Golongan~~\n");
    printf("\tA\tB\tC\tD\tE\n");
    int element;
    for(int i = 0; i < 4; i++){
        printf("%d\t", i + 1);
        for(int j = 0; j < 5; j++){
            element = golmat[i][j];
            if(element == 0){
                printf("-\t");
            }
            else{
                printf("%d\t", element);
            }
        }
        printf("\n");
    }
}
