#include "../utils.h"
#include <string.h>
#include <stdlib.h>

int main() {
    char dest[] = "TO BE REPLACED";
    char* src = "Alice";
    memcpy(dest, src, 5);
    PRINTSTR(dest);

    char* result = memchr(dest, 'R', strlen(dest));
    printf("%ld\n",result - dest + 1); // position at which 'R' is found

    PRINTINT(memcmp("Bob", "Bobb", 3));

    memset(dest, 'X', 3);
    char* allocated_mem = malloc(10);
    // scenario: initialize allocated memory
    memset(allocated_mem, 0, 10);
    PRINTSTR(dest);
    free(allocated_mem);

    memmove(dest, dest + 6, 9);
    PRINTSTR(dest);
}