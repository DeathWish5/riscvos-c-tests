#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

int main() {
    uint64 start = get_time();
    printf("current time_msec = %d\n", start);
    sleep(100);
    uint64 end = get_time();
    printf("time_msec = %d after sleeping 100 ticks, delta = %dms!\n", end, end - start);
    puts("TEST sleep1 passed!\n");
    return 0;
}