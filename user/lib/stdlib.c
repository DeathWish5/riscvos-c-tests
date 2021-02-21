#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static uint64 seed;

void panic(char* m) {
    puts(m);
    exit(-100);
}