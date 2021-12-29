#include <historylist.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

HNode constructHist(){
    HNode newHist = {INIT, 0, "INIT", NULL};
    return newHist;
}

int newAction(HNode* head, const action event, CONSTR info){
    HNode* current = head;
    HNode* new = malloc(sizeof(HNode));

    int pos = 0;
    while(current->next != NULL){
        current = current->next;
        pos++;
    }

    new->event = event;
    new->timestamp = time(NULL);
    strcpy(new->info, info);

    current->next = new;

    return pos;
}

void viewActions(const HNode* head){
    printf("===COMMAND HISTORY===\n");
    printf("=====================\n");
    while(head != NULL){
        char event[5];
        switch(head->event){
            case 0:
                strcpy(event, "INIT");
                break;
            case 1:
                strcpy(event, "ADD");
                break;
            case 2:
                strcpy(event, "REM");
                break;
            case 3:
                strcpy(event, "SNV");
                break;
            case 4:
                strcpy(event, "STAT");
                break;
            default:
                strcpy(event, "UB");
        }

        printf("%s %s %s\n", event, head->info, ctime(&(head->timestamp)));
        head = head->next;
    }
}