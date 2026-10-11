





#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void) {
    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        printf("\r%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);
        fflush(stdout);

        sleep(1);
    }
    return 0;
}
