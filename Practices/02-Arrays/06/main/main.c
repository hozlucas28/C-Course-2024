#include <stdio.h>

#include "../library/main.h"

int main()
{
    char* str = "Oso";

    isPalindrome(str) ? printf("> '%s' is palindrome!\n", str) : printf("> '%s' is not palindrome!\n", str);

    str = "Juana de Arco";
    isPalindrome(str) ? printf("> '%s' is palindrome!\n", str) : printf("> '%s' is not palindrome!\n", str);

    str = "Ana";
    isPalindrome(str) ? printf("> '%s' is palindrome!", str) : printf("> '%s' is not palindrome!", str);

    return 0;
}
