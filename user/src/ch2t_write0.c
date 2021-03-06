#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

const int STACK_SIZE = 0x1000;

uint64 r_sp() {
    uint64 sp;
    __asm__ __volatile__("mv %0, sp": "=r"(sp) ::);
    return sp;
}

uint64 stack_top() {
    uint64 sp = r_sp();
    uint64 top = (sp + STACK_SIZE - 1) & (~(STACK_SIZE - 1));
    return top;
}

/// 正确输出： 
/// Test write0 OK!

int main() {
    assert(write(stdout,  (const void*)0, 10) == -1);
    uint64 top = stack_top(), bottom = top - STACK_SIZE;
    assert(write(stdout, (const void*)(top - 5), 10) == -1);
    assert(write(stdout, (const void*)(bottom - 5), 10) == -1);
    puts("Test write0 OK!");
    return 0;
}
