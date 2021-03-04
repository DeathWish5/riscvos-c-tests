#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = getpid();
    printf("TEST getpid OK! pid = %d\n", pid);
    return 0;
}