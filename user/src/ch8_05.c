#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void fork_test(void(*fn)(int)) {
    const int NUM = 200;
    for (int i = 0; i < NUM; ++i) {
        int pid = fork();
        if (pid == 0) {
            fn(i);
            exit(0);
        }
    }
    int xstate = 0;
    for (int i = 0; i < NUM; ++i) {
        assert(wait(-1, &xstate) > 0);
        assert(xstate == 0);
    }
    assert(wait(-1, &xstate) < 0);
    return 0;
}

void sleep_test(int _i) {
    int current_time = get_time();
    unsigned long long sleep_length = current_time * current_time % 1000 + 1000;
    sleep(sleep_length);
}

void heavy_fork_test() {
    for (int i = 0; i < 10; ++i)
        fork_test(sleep_test);
}

int main() {
    heavy_fork_test();
    return 0;
}