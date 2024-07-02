#include "../utils.h"
#include <string.h>

int main() {
    /**
     * strchr, strrchr: find a char in a strin
     * strstr: find a substring in a string
     */
    const char* sentence = "So we beat on, boats against the current, borned back ceaselessly into the past.";
    const char* word = "boats";
    char* result = strchr(sentence, 'b');
    char* reversed_result = strrchr(sentence, 'b');
    PRINTSTR(result);
    PRINTSTR(reversed_result);
    PRINTSTR(strstr(sentence, word));

    /**
     * fina any characters in a char pool in a string
     */
    const char* lang_history = "C, 1972; C++, 1983; Java, 1995; Python, 1991; Rust, 2010; Go, 2009; Swift, 2014";
    char* breakers = ",;";
    char* pos = lang_history;
    while (pos) {
        pos = strpbrk(pos, breakers);
        if (pos) {
            puts(pos);
            pos++;
        }
    }
}