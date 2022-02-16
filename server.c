#include "libft/libft.h"
#include "header/server.h"

int main(void)
{
    signal(SIGUSR1, signalHandler);
}