#include <stdio.h>
#include <limits.h>

// wide char
#include <wchar.h>

void main() {
    /*
    integer
    */
    // no less than 2 bytes
    short int sint = 1;
    int i = 100;
    // no less than 4 bytes
    long int lint = 1;
    long long int llint = 1;
    unsigned int unint = 1;
    // alias for unsigned int
    size_t st = sizeof(int);
    printf("short int: %d\n", sizeof(sint));
    printf("int: %u\n", sizeof(i));
    printf("long int: %lu\n", sizeof(lint));
    printf("long long int: %llu\n", sizeof(llint));

    printf("max short int: %hd\n", SHRT_MAX);
    printf("max int: %d\n", INT_MAX); // 2^31 - 1
    printf("min unsigned int: %u, max unsigned int: %u\n", 0, UINT_MAX);  // 2^32 - 1
    printf("max long int: %ld\n", LONG_MAX);

    printf("hex of %d is %x, oct of %d is %o\n", i, i, i, i);

    printf("--------------------\n");
    /*
    char: stored as an integer, can be represented as a number or a character
    */
    char a = 'a'; // ASCII 97
    char one = '1'; // ASCII 49
    char zero = 0; // ASCII 0
    char oct_one = '\61'; // ASCII 49, OCT 61
    char hex_one = '\x31'; // ASCII 49, HEX 31'
    printf("char: %c, ASCII: %d\n", a, a);
    printf("char one: %c, ASCII: %d\n", one, one);
    printf("oct one: %c, ASCII: %d\n", oct_one, hex_one);

    wchar_t chinese_one = L'一'; // c95
    printf("code point: %d \n", chinese_one, chinese_one);
    

    /*
    float
    */
   float pie = 3.14f; // 6 digits, 7~8 + 10 ^ -37 ~ 10 ^ 37
   double dpie = 3.14; // 15 ~ 16 digits
   // scientific notation 12345 = 1.2345e4
   // 4 bytes = 32 bits, 1 bit for sign, 8 bits for exponent, 23 bits for mantissa
   printf("size of float: %lu\n", sizeof(pie));
   printf("size of double: %lu\n", sizeof(dpie));

   float lat = 49.21979f; // precision no more than 7 gidits, precision loss with float
   printf("lat: %f\n", lat);

   /*
   constant
   */
  // read only variable, you can still modify the value of the variable by using a pointer
  const int kred = 0xFF0000;
  // marco  this is the real constant value, which is a literal
  #define RED 0xFF0000;
}