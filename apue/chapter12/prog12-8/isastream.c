/* ����12-8 ����������Ƿ��������豸 */
#include <stropts.h>
#include <unistd.h>

int isastream(int fd)
{
	return(ioctl(fd, I_CANPUT, 0) != -1);
}
