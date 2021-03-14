#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = getpid();
    printf("Test getpid OK! pid = %d\n", pid);
    return 0;
}