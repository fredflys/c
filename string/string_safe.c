#include <string.h>
#include <stdlib.h>

/**
 * C11: safe version of string related functions
 * msvc supports these functions since 2005
 * but they are not part of C standard
 * use __STDC_LIB_EXT1__ to check if these functions are available
 */
int main() {
#ifdef __STDC_LIB_EXT1__
    puts("Safe string functions are available");
#else
    puts("Safe string functions are not available");
#endif


}