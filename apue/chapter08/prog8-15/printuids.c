/* ����8-15 ��ӡʵ�ʺ���Ч�û�ID */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
	exit(0);
}

