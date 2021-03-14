#include <string.h>
#include <stdio.h>

const uint64 N = 10;

int main() {
    printf("please enter %d letters.\n", N);
    char line[N];
    memset(line, 0, N);
    for (int idx = 0; idx < N; ++idx) {
        char c = getchar();
        line[idx] = c;
    }
    printf("%d letters entered\n", N);
    for (int idx = 0; idx < N; ++idx) {
        putchar(line[idx]);
    }
    puts(" Test getchar passed!\n");
    return 0;
}