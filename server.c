#include "libft/libft.h"
#include "header/server.h"

int main(void)
{
	pid_t serverPID = getpid();
	if (serverPID)
	ft_putnbr_fd(serverPID, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);
	while(1)
	{
		ft_putstr_fd("Signal waiting...\n", 1);
		pause();
		ft_putstr_fd("BYE\n",1);
	}
	return (0);
}

void	signalHandler(int sigNum)
{
	ft_putstr_fd("I got it!!\n", 1);
	ft_putnbr_fd(sigNum, 1);
	ft_putstr_fd("\n", 1);
	return;
}