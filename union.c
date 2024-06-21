#include "utils.h"


/**
 * union store: store different data types in the same memory location
 * use it when you know you will only use one of the members at a time, usually used with switch 
 */

typedef union Operand {
    int int_operand;
    char* string_operand;
} Operand;

#define OPERATOR_INT 1
#define OPERATOR_STRING 2

typedef struct Instruction {
    int operator;
    Operand operand;
} Instruction;

void Process(struct Instruction *instruction) {
    switch (instruction->operator) {
        case OPERATOR_INT:
            PRINTINT(instruction->operand.int_operand);
            break;
        case OPERATOR_STRING:
            puts(instruction->operand.string_operand);
            break;
        default:
            fprintf(stderr, "Invalid operator\n");
    }   
}

// union example: check endianness
int IsBigEndian() {
    union {
        short s;
        char c[sizeof(short)];
    } _ = {.s = 0x100};

    return _.c[0] == 1;
}

int IsBigEndianByPtr() {
    short s = 0x100;
    char *ptr = (char *) &s;
    return ptr[0] == 1;
}

// union exmplae: change endianess
int ToggleEndianess(int num) {
    // use macor to vaoid initializing an variabl-sized object
    #define size sizeof(int)
    union {
        int num;
        char c[size];
    } block = {.num = num};

    for (int i = 0; i <  size / 2; i++) {
        char temp = block.c[i];
        block.c[i] = block.c[size - i - 1];
        block.c[size - i - 1] = temp;
    }

    return block.num;
}

int main() {
        /**
     * union example: switch operations
     */
    Instruction Instruction = {
        .operator = OPERATOR_STRING,
        .operand = {
            .string_operand = "union type is great"
        }
    };
    Process(&Instruction);

    PRINTINT(IsBigEndian());
    PRINTINT(IsBigEndianByPtr());
    PRINTHEX(0x1234);
    PRINTHEX(ToggleEndianess(0x1234));
}