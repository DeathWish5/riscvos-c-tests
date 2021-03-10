#include <unistd.h>
#include <stdio.h>

const int WIDTH = 10;
const int HEIGHT = 5;

/*
理想结果：三个程序交替输出 ABC
*/

int main() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int _ =  0; _ < WIDTH; ++_) { putchar('C'); }
        printf(" [%d/%d]\n", i + 1, HEIGHT);
        sched_yield();
    }
    puts("Test write C OK!\n");
    return 0;
}