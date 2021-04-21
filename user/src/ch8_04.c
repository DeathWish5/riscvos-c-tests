#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char BUG[1000];
    open("fname0", O_CREATE | O_WRONLY);
    open("fname1", O_CREATE | O_WRONLY);
    printf("GOOD %s", "LOCK\n");
    write(65537, (void*) -996, -233);
    read(-555, (void*)8888, 777777777777777ULL);
    close(-939);
    close(0);
    close(1);
    close(2);
    puts("I need fuzzy ...");
    open("@#$%**??!- ∑_{i = 0}^{over} -!??**@#$%", 414);
    open("编程是一件危险的事情", O_CREATE | O_WRONLY);
    set_priority(-7);
    set_priority(ULONG_MAX);
    mailwrite('G', BUG, -535);
    mailwrite(-133, BUG - 20, 1234567890);
    fstat(0, (void*)20);
    fstat(313, (void*)20);
    link("nonono", "yesyesyes");
    link("fname0", "fname1");
    link("fname1", "fname0");
    link("fname0", "fname0");
    link("\0", "fname1");
    sys_unlinkat(555, "➑➑➑➑➑➑", -1);
    sys_linkat(0, "QAQ", -7, "❆❆❆❆❆", 0);
    wait(-645);
    return 0;
}