/* ����5-1 ��getc��putc����׼���븴�Ƶ���׼��� */
#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF) {
			perror("output error");
			exit(1);
		}

	if (ferror(stdin)) {
		perror("input error");
		exit(1);
	}

	exit(0);
}
