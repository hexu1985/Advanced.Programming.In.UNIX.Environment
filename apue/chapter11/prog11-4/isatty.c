/* ����11-4 POSIX.1 isatty������ʵ�� */
#include <termios.h>

int isatty(int fd)
{
	struct termios term;
	return(tcgetattr(fd, &term) != -1);
}
