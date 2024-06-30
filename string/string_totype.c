#include "../utils.h"
#include <stdlib.h>
#include <errno.h>

int main() {
    /**
     * atox: simple to use for simple scenarios
     */
    PRINTINT(atoi(" 123b"));
    PRINTFLT(atof(" 12.4"));


    /**
     * strtox: more complex but more powerful, multiple bases, multiple parsing on the same string, error handling
     * parameters: str, endptr, base
     * str: the string to parse
     * endptr: pointer to the first character that is not part of the number, i.e. the first position after parsing. value will be assigned to this pointer after parsing. that's why the type should be a pointer to a pointer
     * base: the base of the number, 0 for auto-detect, 2-36 for explicit base
     */
    char const* const longstr = "1 2000000000000000000000000 3 -4 25abcd bye";
    char const* start = longstr;
    char* end;

    PRINTSTR(longstr);
    while (1) {
        errno = 0;

        const long num = strtol(start, &end, 10);
        
        // parsing failed if end is the same as start
        if (start == end) break;

        if (errno == ERANGE) {
            perror("strtol\n");
        } else {
            // %.*s: print a string with a variable length that given in the next argument
            printf("%.*s\t ==> %ld\n", (int) (end - start), start, num);
        }

        start = end;
    }
}