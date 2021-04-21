#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int prot = 3;
    mmap((void *) 0, 0x4000ULL, prot);
    puts("do something ...");
    return 0;
}