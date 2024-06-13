#include "utils.h"
#include "stdlib.h"

void point_to_nowhere(int* ptr) {
    int num = 3;
    ptr = &num;
    // should have pointed it to NULL after use
    // ptr = NULL;
}

void sum(int arr[], int length, int *result) {
    *result = 0;
    for (int i = 0; i < length; i++) {
        *result += arr[i];
    }
}

void swap(void *former, void *latter, size_t size) {
    void *temp = malloc(size);
    if (temp) {
        memcpy(temp, former, size);
        memcpy(former, latter, size);
        memcpy(latter, temp, size);
        free(temp);
    }
}

/*
do {...} while(0) ensures that the macro is used as a single statement so that it can be used safely in if-else statements
*/
#define SWAP(former, latter) do { typeof(former) temp = former; former = latter; latter = temp; } while(0)

int main() {
    /*
    1. basics: pointer size, pointer declaration, reference and dereference
    */
    int a = 11;
    int b = 20;
    // & is reference operator
    int *p = &a;
    /*
    Pointer Size:
    4 bytes for 32-bit system
    8 bytes for 64-bit system
    */
    PRINTPTR(p);
    /*
    * is the dereference operator on the right side and on the left side it is used to declare a pointer.
    */
    PRINTINT(*p);


    /*
    2. const pointer, pointer to const, const pointer to const
    const is for whatever comes before it
    */
    // const pointer to int, which means the pointer is constant, but the value it points to can be changed
    int * const const_addr_ptr = &a;
    *const_addr_ptr = 12;

    // pointer to const int, which means the pointer is not constant, but the value it points to is constant
    int const * const_val_ptr = &a;
    const_val_ptr = &b;
    // const pointer to const int, which means the pointer is constant and the value it points to is also constant
    int const *const const_ptr_int = &a;

    /*
    3. null pointer, wild pointer
    */
    int* null_ptr = NULL;
    int* wild_ptr;
    point_to_nowhere(wild_ptr);

    /*
    4. left and right value
    on the left it will always be memory space or storage, on the right it will always be the value
    */
    int x = 2;
    int *px = &x;
    int y = *px;

    int arr[4] = {0};
    int *parr = arr;
    *(parr++) = 2;

    /*
    5. pointer in function
    pass the pointer to a function to change the value of the pointer
    pros: 
    1. no need to copy from register to register and back to memory thus more efficient
    2. multipel values can be returned this way
    */ 
    int res;
    sum(arr, 4, &res);

    /*
    6. dynamic memory allocation
    variables are stored in stack, and the memory is automatically freed when the function returns
    we exit the function and the stack is popped off and variables will go away
    but if we want to use variables outside the function, we need to use heap memory
    we can allocate memory on our own, and it means we have to take care of the memory
    */
    #define HEAP_ARR_LENGTH 5
    /**
     * malloc is used to allocate memory on the heap but the memory is not initialized so it may have funny values. you have to initialize it yourself
     * 
    */
    int *heap_arr1 = malloc(sizeof(int) * HEAP_ARR_LENGTH);
    for (int i = 0; i < HEAP_ARR_LENGTH; i++) {
        heap_arr1[i] = i;
    }
    PRINTARR_INT(heap_arr1, HEAP_ARR_LENGTH);
    free(heap_arr1);

    /**
     * calloc is used to allocate continue memory on the heap and it initializes the memory to 0
     * since there is initialization involved, it is slower than malloc but you don't have to worry about funny values
    */
   int *heap_arr2 = calloc(HEAP_ARR_LENGTH, sizeof(int));
   PRINTARR_INT(heap_arr2, HEAP_ARR_LENGTH);
   /**
    * relloc is used to reallocate memory on the heap. It's like trade-in: you bring in the old memory space and compiler will check if there is available space right after the old one. If yes, it will just extend. If not, it will find a new space and copy the old memory to the new space and free the old space
    * 
   */
    heap_arr2 = realloc(heap_arr2, HEAP_ARR_LENGTH * 2 * sizeof(int));
    PRINTARR_INT(heap_arr2, HEAP_ARR_LENGTH * 2);


    /**
     * allocating memory space may fail, even though unlikely, so you should always check if the memory allocation is successful
    */
    if (heap_arr2) {
        PRINTARR_INT(heap_arr2, HEAP_ARR_LENGTH * 2);
    }

    free(heap_arr2);

    /**
     * 7. function pointer
    */
   void (*sum_ptr) (int arr[], int length, int *result) = &sum;
   (*sum_ptr)(arr, 4, &res);

    typedef void (*sum_ptr_def) (int arr[], int length, int *result);
    sum_ptr_def sum_twin = sum;

    /**
     * 8. example: a more generic swap
    */
    int num1 = 1;
    int num2 = 2;
    swap(&num1, &num2, sizeof(int));
    PRINTINT(num1);
    PRINTINT(num2);

    // macro version of swap
    SWAP(num1, num2);
    PRINTINT(num1);
    PRINTINT(num2);

    return 0;
}