#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static volatile int keep_running = 1;

void show_cursor() {
    printf("\e[?25h");
    fflush(stdout);
}

void signal_handler(int sig) {
    printf("\nCaught signal %d (Ctrl+C). Restoring cursor and exiting.\n", sig);
    keep_running = 0; 
}

int main() {
    printf("\e[?25l");
    signal(SIGINT, signal_handler);
    printf("Current Time\n");
    while (keep_running) {
        time_t currentTime;
        time(&currentTime);
        struct tm *t = localtime(&currentTime);
        int hour = t->tm_hour;
        if (hour > 12) {
            hour = hour - 12;
        }
        int min = t->tm_min;
        int sec = t->tm_sec;
        printf("%02d:%02d:%02d\r", hour, min, sec);
	fflush(stdout);
        usleep(10000);
    }
    show_cursor();
    return 0;
}

