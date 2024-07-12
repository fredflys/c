#include "stdio.h"
#ifdef _WIN32
    #include <sys/timeb.h>
#elif defined(__unix__) || defined(__APPLE__)
    #include <sys/time.h>
#endif


typedef long long long_time_t;

long_time_t timems() {
// mingw does not support C11 timespec very well so use win32 timeb is better
#ifdef _WIN32
    struct timeb now;
    ftime(&now);
    return now.time * 1000LL + now.millitm;
#elif defined(__unix__) || defined(__APPLE__)
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_sec * 1000000LL + now.tv_usec / 1000;
#elif defined(__STDC__) && __STDC__VERSION__ == 201112L
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return now.tv_sec * 1000LL = now.tv_nsec / 1000000;
#else 
    time_t now = time(NULL);
    return now * 1000LL;
#endif

}