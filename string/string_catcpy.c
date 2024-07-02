#include "../utils.h"
#include <string.h>

int main() {
    char* src = " John";
    char dest[20] = "Hello,";
    strcat(dest, src);
    puts(dest);

    char* from = " Lilyaaa";
    char to[] = "Hello, ";
    strcpy(to, from);
    puts(to);
}