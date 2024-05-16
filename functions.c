#include <stdio.h>
#include <stdarg.h>

/*
in C++, zero parameter means zero parameter, not indefinite parameters.
return type is defaulted to int if not specified
*/
FunctionUnlimitedParameters() {
    printf("Function with indefinite parameters\n");
    return 1;
}

/*
function prototype
usage: header filer
why: for invoatino of the function  return type and argument type are all required, implementaion is not necesssary
*/
int FunctionZeroParameter(void);


/*
file scope
*/
int global_var = 1;
int Scope() {
    /*
    variable type: auto, meaning the variable is automatically allocated in the stack
    variable data type: int
    */
    auto int val = 1;

    /*
    static variable: the variable is allocated in the data segment, and the value is kept between function calls, default value is 0 if not specified, better to specify the value, otherwise the value will be affected by function calls
    */
    static int static_val;
    printf("static_val: %d\n", static_val);

    /*
    register variable: the variable is allocated in the register, which is faster than the stack, but the number of register is limited, and the variable is not accessible by the address
    not recommended to use, as the compiler is smart enough to optimize the code
    */
   register int reg_val = 1;

    /*
    block scope: visible only within the block, such as if else block
    */
    {
        int val = 2;
    }

}

int Varargs(int arg_cnt, ...) {
    // define the argument list
    va_list args;

    // use args
    va_start(args, arg_cnt);
    for (int i = 0; i < arg_cnt; i++) {
        int arg = va_arg(args, int);
        printf("arg %d: %d\n", i, arg);
    }
    
    // clean up the argument list
    va_end(args);
}


int main() {
    FunctionUnlimitedParameters(1,2,3);
    FunctionZeroParameter();
    Scope();
    Varargs(3, 10, 2, 300);
    return 1;
}

int FunctionZeroParameter(void) {
    printf("no parameter is allowed here.\n");
}