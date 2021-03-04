#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

int main() {
    char* fname = "fname1";
    int fd = open(fname, O_CREATE | O_WRONLY, O_RDWR);
    assert(fd > 0);
    Stat stat;
    int ret = fstat(fd, &stat);
    assert(ret == 0);
    assert(stat.mode == FILE);
    assert(stat.nlink == 1);
    close(fd);
    puts("TEST fstat OK!\n");
    return 0;
}