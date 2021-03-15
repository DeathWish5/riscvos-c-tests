#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

int main() {
    int64 start = get_time();
    printf("current time_msec = %d\n", start);
    sleep(100);
    int64 end = get_time();
    printf("time_msec = %d after sleeping 100 ticks, delta = %dms!\n", end, end - start);
    puts("Test sleep1 passed!\n");
    return 0;
}