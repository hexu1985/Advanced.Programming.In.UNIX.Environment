/* DEBUG����;�� */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int flag;

int main()
{
	char *pstr;

	if ((pstr = getenv("DEBUGON")) == NULL)
		flag = 0;
	else
		flag = 1;

	if (flag == 1)
		printf("���Ǵ���־�����!\n");

	return;
}
