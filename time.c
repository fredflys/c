#include <time.h>
#include <sys/timeb.h>
#include "./utils.h"
#include "time_utils.h"
#include <unistd.h>

int main() {
    time_t; // elapsed time in seconds since epoch, time zone independent
    __clock_t; // elapsed time in clock ticks, usually for CPU time
    // struct tm; // human readable time but not storage friendly
    struct timespec; // most recommended, C11 and msvc, more accurate time in seconds and nanoseconds
    struct timeb; // for platforms not supporting C11 and msvc, more accurate time in seconds and milliseconds
#ifdef __unix__
    struct timeval; // for platforms not supporting C11 and msvc, more accurate time in seconds and microseconds
#endif
    /**
     * time stamp
     */
    time_t now;
    time(&now);
    printf("Seconds since epoch: %ld\n", now);
    PRINTLONG(timems());

    /**
     * human readable time
     */
    struct tm *calendar_time =  localtime(&now);
    struct tm *gmt_time = gmtime(&now);

    PRINTINT(calendar_time->tm_year); // elapsed years since 1970
    PRINTINT(calendar_time->tm_mon); // jan is 0
    PRINTINT(calendar_time->tm_mday);
    PRINTINT(calendar_time->tm_hour);
    PRINTINT(calendar_time->tm_min);
    PRINTINT(calendar_time->tm_sec);

    // from human readable time to time stamp
    time_t epoch_time = mktime(calendar_time);
    printf("current date and time is: %s", asctime(calendar_time));
    printf("current greenwich mean time is: %s", asctime(gmt_time)); 
    // PRINTSTR(ctime(&calendar_time));
    
    char formatted_time[20];
    strftime(formatted_time, sizeof(formatted_time), "%Y%m%d%H%M%S", calendar_time);

    // append ms
    int current_ms = timems() % 1000;
    sprintf(formatted_time + 14, ".%03d", current_ms);
    PRINTSTR(formatted_time);

    /**
     * from formatted time string back to human readable time
     * */ 
    #define _XOPEN_SOURCE // for strptime
    char* time_string = "2024-07-12 03:09:20.123";
    struct tm parsed_time;
    char* unparsed_string = strptime(time_string, "%Y-%m-%d %H:%M:%S", &parsed_time);
    // puts(unparsed_string);
    printf("parsed time: %s", asctime(&parsed_time));
    // printf("unparsed string: %s\n", unparsed_string); // ms is not parsed
    
    // scan from a given string instead of standard input
    int ms;
    sscanf(".123", ".%3d", &ms);

    /**
     * calculate time difference
     */
    long_time_t start = timems();
    sleep(0.3);
    long_time_t end = timems();
    PRINTLONG(end - start);

    // how much CPU time is used 
    // CPU is constantly switching between contexts so CPU time is equal to real time
    clock_t start_cpu = clock();
    sleep(0.2);
    clock_t end_cpu = clock();
    printf("CPU time: %f\n", (double) (end_cpu - start_cpu) / CLOCKS_PER_SEC);
    PRINTDBLE((double) (end_cpu - start_cpu) / CLOCKS_PER_SEC);
}