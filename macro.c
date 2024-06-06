//  #include <stdio.h>
/*
  inclusion of the prototype of the function is enough
  proprotype is just for the compiler to know the signature of the function
  the implementation is in the standard library and not relevant to the user here

  header file will be expaned recursively by preprocessor
*/
extern int printf (const char *__restrict __format, ...);
extern int puts (const char *__s);

/*
macro function will be expanded and replaced by the preprocessor
so the function is not called, but the code is replaced
to prevent the unexpected behavior, the arguments should be enclosed by parentheses so that every variable will be treated as an expression (single entity)

marco and function: replacement v.s  evaluation

use \ for line break

no type checking for macro
*/
#define MAX(a, b) a > b ? a : b
#define TRUE_MAX(a, b) (a) > (b) ? (a) : (b)
#define IS_HEX_CHAR(ch) \
((ch) >= '0' && (ch) <= '9') || \
((ch) >= 'a' && (ch) <= 'f') || \
((ch) >= 'A' && (ch) <= 'F')


/*
make use of predefined macros and operators
*/

/*
1 example: only print the debug message when the debug flag is on
the debug flag can be defined in the makefile
*/
#define DEBUG

void dump(char* msg) {
  #ifdef DEBUG
    printf("DEBUG: %s\n", msg);
  #endif
}

/*
2 example: println
function version and macro version
*/
void Println(const char* format, ...) {
  #include <stdarg.h>
  #include <stdio.h>

  va_list args;
  va_start(args, format);

  vprintf(format, args);  
  printf("\n");

  va_end(args);
}

// ## operator is called paste operator, which concatenates two tokens together. in this case, when the variable arguments are empty, the comma will be removed
#define PRINTLN(format, ...) printf(format"\n", ##__VA_ARGS__);
// # operator is called stringizing operator, which converts the token to a string
#define PRINT_INT(value) printf(#value": %d\n", value);
  
/*
3 example: print the metainfo of the code
(file.c : line_number) function_name
*/
#define PRINT_INFO(format, ...) printf("("__FILE__" : %d) %s "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)

int main() {
    printf("Print.\n");
    puts("Puts.\n");

    int max = MAX(1, MAX(3, 2));
    printf("false max: %d\n", max);
    max = TRUE_MAX(1, TRUE_MAX(3, 2));
    printf("true max: %d\n", max);
    printf("is hex char: %d\n", IS_HEX_CHAR('a'));

    dump("Debug");

    /*
    predefined macros
    */
    #if __STDC_VERSION__ >= 201112
      puts("C11+ \n");
    #elif __STDC_VERSION__ >= 199901
      puts("C99+ \n");
    #else
      puts("C??\n");
    #endif

    Println("there will be a new line.");
    PRINTLN("there will be a new line.");

    int random_number = 3;
    PRINT_INT(random_number);
    PRINT_INFO("info: %d", random_number);
}

