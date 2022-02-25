#include "libft/libft.h"
#include "header/client.h"

int	main(int argc, char *argv[])
{
	int serverPID;
	int len;
	int i;

	if (argc != 3)
		return (0);
	serverPID = ft_atoi(argv[1]);
	if (!(serverPID > 100 && serverPID < 100000))
		return (0);
	i = 0;
	len = ft_strlen(argv[2]);
	while (i < len)
	{
		formatWord(argv[2][i], serverPID);
		i++;
	}
	return (0);
}

void	formatWord(char word, int serverPID)
{
	unsigned char num;
	int idx;

	idx = 0;
	num = 0x80;
	while (idx < 8)
	{
		sendSignal(word & num, serverPID);
		num >>= 1;
		idx++;
	}
	return ;
}

void	sendSignal(int sig, int serverPID){
	if(sig)
		kill(serverPID, SIGUSR2);
	else
		kill(serverPID, SIGUSR1);
	usleep(100);
	return ;	
}