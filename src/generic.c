#include "generic.h"

void clearbuffer(){
    while(getc(stdin) != '\n'){}
}
