#include "libft/libft.h"
#include "header/client.h"

int	main(int argc, char *argv[])
{
	int serverPID = ft_atoi(argv[1]);
	if (argc != 3 || !(serverPID > 100 && serverPID < 100000))
		return (0);
	ft_putstr_fd("ok",1);
	kill(serverPID, SIGUSR1);
	kill(serverPID, SIGUSR2);	
	return (0);
}