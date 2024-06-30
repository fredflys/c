#include "../utils.h"
#include <string.h>

void swap(char** strs, int i, int j) {
    char* temp = strs[i];
    strs[i] = strs[j];
    strs[j] = temp;
}

int partition(char* strs[], int low, int high) {
    const char* pivot_val = strs[high];
    int partition = low;
    for (int i = low; i < high; i++) {
        if (strcmp(strs[i], pivot_val) < 0) {
            swap(strs, i, partition++);
        }
    }
    swap(strs, partition, high);
    return partition;
} 

void quick_sort(char* strs[], int low, int high) {
    if (low >= high) return;
    int pivot = partition(strs, low, high);
    quick_sort(strs, low, pivot - 1);
    quick_sort(strs, pivot + 1, high);
} 

int main() {
    /**
     * strlen() returns the length of the string but it is unsalfe because it checks null terminator until it finds it. what if the string is not null terminated?
     * 
     * strlen_s() [msvc] | strnlen() [posix] is a safe version of strlen() which takes the max length of the string as a parameter
     */
    PRINTINT(strlen("Hello"));
    PRINTINT(strnlen("Hello, now it is safer!", 13));

    /**
     * example of strcmp: quick sort on a string array 
     */
    char* names[] = {"Bob", "Alice", "Charlie", "Frank", "Grace", "David", "Eve"};
    PRINTARR_STR(names, 7);
    quick_sort(names, 0, 6);
    printf("after sort: \n");
    PRINTARR_STR(names, 7);
}