/* DEBUG�ľ�;�� */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
#ifdef DEBUGON
	printf("���Ǵ���־�����!\n");
#endif

	return;
}
