#include <stdio.h>

// macro examples
#define PRINTLN(format, ...) printf(format"\n", ##__VA_ARGS__)
#define PRINTINT(value) printf(#value": %d\n", value)
#define PRINTCHAR(value) printf(#value": %c\n", value)
#define PRINTF(format, ...) printf("("__FILE__" : %d) %s "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
