/* ����1-4 ��ӡ����ID */
#include <unistd.h>
#include <stdio.h>

int main(void) 
{
	printf("hello world from process ID %d\n", getpid());
	exit(0);
}

