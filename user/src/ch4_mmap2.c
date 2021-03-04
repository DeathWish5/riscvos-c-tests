#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int main() {
    uint64 start = 0x10000000;
    uint64 len = 4096;
    int prot = 2;
    assert(len == mmap((void*)start, len, prot));
    uint8* addr = (uint8*)start;
    // *addr = (uint8)start; // can't write, R == 0 && W == 1 is illegal in riscv
    puts("If core dumped, Test 04_3 OK!\n");
    assert(*addr != 0);
    return 0;
}