
#include <string.h>

#include "./main.h"

void  reverseString(char* _string) {
    char* head = _string;
    char* tail = _string + strlen(_string) - 1;
    char aux;

    while (head != tail) {
        aux = *head;
        *head = *tail;
        *tail = aux;

        head++;
        tail--;
    };

}
