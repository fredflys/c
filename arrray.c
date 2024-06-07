#include "utils.h"
#include "wchar.h"

#include "stdlib.h"
#include "time.h"
// length has to be given because it is not known from the array
int sum(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum;
}

// for the two-dimension array, the col has to be specified otherwise the complier won't know where to find the first element
void sum2(int row, int col, int arr[][col], int result[]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i] += arr[i][j];
        }
    }
}

/*
example: shuffle
*/
void shuffle(int arr[], int length) {
    srand(time(NULL));
    for (int i = length - 1; i > 0; --i) {
        int random_index = rand() % (i + 1);
        swap(arr, i, random_index);
    }
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
example: quick sort
*/
int partition(int arr[], int low, int high) {
    int pivot_val = arr[high];
    int partition = low;
    for (int i = low; i < high; ++i) {
        // make sure everything that comes before partition is less than pivot value
        if (arr[i] < pivot_val) {
            swap(arr, i, partition++);
        }
    }
    // parition is the place where the pivot value shold go
    swap(arr, partition, high);
    return partition;
}

void quick_sort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
}

int main() {
    /*
    initialization
    */
    int int_arr[10] = {1,2,3};
    PRINTINT(int_arr[0]);
    // from C99
    char char_arr[10] = {[2] = 'C', 'D', 'E'};
    PRINTCHAR(char_arr[4]);
    
    /*
    string: a char array that always ends with a null character \0
    */

    // no need to give length here, induced from literal value
    char string[] = "Hello";
    PRINTLN("%s", string);
    // there will be an implicit null character \0 at the end of the string, which increments the length
    PRINTINT((int) sizeof(string) / (int) sizeof(char));
    char chinese_chars[] = "晚上";
    wchar_t chinese_wchars[] = L"晚上";
    PRINTLN("%s", chinese_chars);
    PRINTLN("%ls", chinese_wchars);

    /*
    pass an array to a function
    you have to pass the length, because the array is passed as a pointer to the first element  
    no extra information about the length is passed 
    that's why C array is fast
    */
    sum(int_arr, 3);
    int result[2] = {0};
    int scores[2][3] = {{1,2,3}, {4,5,6}};
    sum2(2, 3, scores, result);
    PRINTARR_INT(result, 2);

    /*
    example: shuffle an array
    */
    int length = 50;
    int nums[length];
    for (int i = 0; i < length; i++) {
        nums[i] = i;
    }
    shuffle(nums, length);
    PRINTARR_INT(nums, length);

    /*
    quick sort
    */
    quick_sort(nums, 0, length - 1);
    PRINTARR_INT(nums, length);
}