#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/// 正确输出：（无报错信息）
/// get_time OK! {...}
/// Test sleep OK!

int main() {
    int64 current_time = get_time();
    assert(current_time > 0);
    printf("get_time OK! %d\n", current_time);
    int64 wait_for = current_time + 3000;
    while (get_time() < wait_for) {
        sched_yield();
    }
    puts("Test sleep OK!\n");
    return 0;
}