/* DEBUG����;�� */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *pstr;

	if ((pstr = getenv("DEBUGON")) == NULL)
		;
	else
		printf("���Ǵ���־�����!\n");

	return;
}
