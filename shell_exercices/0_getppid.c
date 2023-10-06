#include "main.h"

int main(void)
{
    pid_t my_pid, my_ppid;

    my_pid = getpid();
    my_ppid = getppid();

    printf("My pid %u\n", my_pid);
    printf("My parent pid %u\n", my_ppid);

    return (0);
}