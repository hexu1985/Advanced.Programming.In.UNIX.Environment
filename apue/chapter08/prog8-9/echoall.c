/* ����8-9 �������������в��������л����ַ��� */
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	char **ptr;
	extern char **environ;

	for (i = 0; i < argc; i++)		/* echo all command-line args */
		printf("argv[%d]: %s\n", i, argv[i]);

	for (ptr =  environ; *ptr != 0; ptr++)	/* and all env strings */
		printf("%s\n", *ptr);

	exit(0);
}