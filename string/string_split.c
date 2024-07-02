#include "../utils.h"
#include <string.h>
#include <stdlib.h>

typedef struct Language {
    char* name;
    int year;
} Language;

void resize_if_needed(int size, int* capacity, Language** languages) {
    if (size == *capacity) {
        *capacity *= 2;
        languages = realloc(*languages, sizeof(Language) * *capacity);
        if (!languages) {
            perror("realloc");
            exit(1);
        }
    }
}

int main() {
    char lang_history[] = "C, 1972; C++, 1983; Java, 1995; Python, 1991; Rust, 2010; Go, 2009; Swift, 2014";

    char* delimiters[] = {",", ";"};

    // dynamic array
    int size = 0;
    int capacity = 3;
    Language* languages = malloc(sizeof(Language) * capacity);
    if (!languages) {
        perror("malloc");
        exit(1);
    }

    // strtok will modify the original string by change the delimiter to null terminator
    char* pos = strtok(lang_history, delimiters[0]);
    while (pos) {
        Language lang;
        lang.name = pos;

        pos = strtok(NULL, delimiters[1]);
        if (pos) {
            lang.year = atoi(pos);
            resize_if_needed(size, &capacity, &languages);
            languages[size++] = lang;
            pos = strtok(NULL, delimiters[0]);
        }
    }

    for (int i = 0; i < size; i++) {
        printf("Language: %s, Year: %d\n", languages[i].name, languages[i].year);
    }
}