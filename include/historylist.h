#ifndef HISTORYLIST_H_
#define HISTORYLIST_H_

#include <time.h>
#include "gtypes.h"

typedef enum {
    INIT,
    ADD_DATA,
    REM_DATA,
    SORT_AND_VIEW,
    VIEW_STAT
} action;

typedef struct HistoryList{
    action event;
    time_t timestamp;
    char info[20];
    struct HistoryList* next;
} HNode;

HNode constructHist();
int newAction(HNode* head, action event, CONSTR info);
void viewActions(const HNode* head);

#endif