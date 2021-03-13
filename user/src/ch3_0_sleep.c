#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/// 正确输出：（无报错信息）
/// get_time OK! {...}
/// TEST sleep OK!

int main() {
    int64 current_time = get_time();
    assert(current_time > 0);
<<<<<<< HEAD
    printf("get_time OK! %lu\n", current_time);
    int64 wait_for = current_time + 3000;
=======
    printf("get_time OK! %d\n", current_time);
    uint64 wait_for = current_time + 3000;
>>>>>>> b23539a42bbd92a3ab3809b56994f49d6aa27057
    while (get_time() < wait_for) {
        sched_yield();
    }
    puts("Test sleep OK!\n");
    return 0;
}