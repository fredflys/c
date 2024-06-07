#include <stdio.h>

// macro examples
#define PRINTLN(format, ...) printf(format"\n", ##__VA_ARGS__)
#define PRINTINT(value) printf(#value": %d\n", value)
#define PRINTCHAR(value) printf(#value": %c\n", value)
#define PRINTF(format, ...) printf("("__FILE__" : %d) %s "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define PRINTARR_INT(array, length) PRINTARR("%d ", array, length)
#define PRINTARR(format, array, length) \
{ \
    int i = 0; \
    for (int i = 0; i < length; i++) { \
        printf(format, array[i]); \
    } \
    printf("\n"); \
} 
