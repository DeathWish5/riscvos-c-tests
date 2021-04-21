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

int hash(int n) {
    uint64 r = 6364136223846793005ULL * n + 1;
    return r >> 33;
}

const uint64 START = 0x10000;
const uint64 LEN = 0x10000;

void mmap_test(int i) {
    char* a;
    *(a + (hash(i) % LEN)) = 'a';
    *(a + (hash(i * 3 + 1) % LEN));
}

int main() {
    int prot = 3;
    mmap((void*)START, LEN, prot);
    fork_test(mmap_test);
    return 0;
}