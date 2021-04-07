/* ����14-6 ���˳��򣬽���д�ַ����Сд�ַ� */
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		if (isupper(c))
			c = tolower(c);
		if (putchar(c) == EOF) {
			perror("output error");
			exit(1);
		}
		if (c == '\n')
			fflush(stdout);
	}
	exit(0);
}
