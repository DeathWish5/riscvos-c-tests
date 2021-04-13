#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/// 不是测例，方便本地测试

const char LF = 0x0a;
const char CR = 0x0d;
const char DL = 0x7f;
const char BS = 0x08;

int tail = 0;

int main()
{
    char line[1024];
    puts("C user shell");
    printf(">> ");
    fflush(stdout);
    for (;;)
    {
        char c = getchar();
        switch (c)
        {
        case LF:
        case CR:
            printf("\n");
            if (tail != 0)
            {
                line[tail++] = '\0';
                int cpid = spawn(line);
                if (cpid < 0)
                {
                    printf("invalid file name\n");
                    printf(">> ");
                    fflush(stdout);
                    continue;
                }
                int xstate = 0, exit_pid = 0;
                for (;;)
                {
                    exit_pid = waitpid(cpid, &xstate);
                    if (exit_pid == -1)
                    {
                        sched_yield();
                    }
                    else
                    {
                        assert(cpid == exit_pid);
                        printf("Shell: Process %d exited with code %d\n", cpid, xstate);
                        break;
                    }
                }
                tail = 0;
            }
            printf(">> ");
            fflush(stdout);
            break;
        case BS:
        case DL:
            if (tail != 0)
            {
                putchar(BS);
                printf(" ");
                putchar(BS);
                fflush(stdout);
                --tail;
            }
            break;
        default:
            putchar(c);
            fflush(stdout);
            line[tail++] = c;
            break;
        }
    }
}