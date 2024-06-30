#include "../utils.h"
#include <ctype.h>

int main() {
    /**
     * all of these functions are looking up in a table
     * and do a bitwise operation with a type bit value to check if the character is of that type
     */
    PRINTINT(isdigit('4'));
    PRINTINT(isalnum('b'));
    PRINTINT(isspace(' '));
    PRINTINT(isupper('c'));
    PRINTINT(ispunct(';'));
}