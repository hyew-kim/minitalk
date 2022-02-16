#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signo)
{
    printf("Catch! %d", signo);
    exit(1);
}

int main(void)
{
    //error시 SIG_ERR 리턴
    if(signal(SIGINT, signal_handler) == SIG_ERR)
    {
        printf("Can't catch");
        exit(0);
    }
}