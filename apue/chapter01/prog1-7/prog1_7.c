/* ����1-7 ��ӡ�û�ID����ID */
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	exit(0);
}
