/* ����1-3 �ñ�׼I/O����׼���븴�Ƶ���׼��� */
#include <unistd.h>
#include <stdio.h>

void err_sys(char *, int);

int main(void)
{
	int c;

	while ((c=getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF) 
			err_sys("�������!", 1);			

	if (ferror(stdin))
		err_sys("�������!", 2);

	exit(0);
}

void err_sys(char *str, int errno)
{
	fprintf(stderr, str);
	exit(errno);
}
