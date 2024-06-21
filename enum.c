#include "utils.h"


/**
 * enum
 */
typedef enum {
    JPG, PNG, BMP, UNKNOWN
} PIC_FORMAT;

PIC_FORMAT GuessPicFormat(char* path) {
    FILE *file = fopen(path, "rb");
    PIC_FORMAT format = UNKNOWN;
    if (file) {
        char buffer[8] = {0};
        size_t bytes_count = fread(buffer, 1, 8, file);
        if (bytes_count == 8) {
            if (*((short *) buffer) == 0x4D42) {
                format = BMP;
            }
        }

        fclose(file);
    }

    return format;
}

int main() {
    /**
     * enum example
     */
    PRINTINT(GuessPicFormat("test.jpg"));
}