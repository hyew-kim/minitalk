#ifndef CLIENT_H
# define CLIENT_H

/*header*/
# include <signal.h>
/*prototype*/
void	formatWord(char word, int serverPID);
void	sendSignal(int sig, int serverPID);

#endif
