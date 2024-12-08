
#include "../library/main.h"

#include <stdio.h>

int main() {
    char _string[] = "Hello world of Go (Golang)!";

    printf("> String: \"%s\".", _string);

    reverseString(_string);

    printf("\n> String reversed: \"%s\".", _string);

    return 0;
}
