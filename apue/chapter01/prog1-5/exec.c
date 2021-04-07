/* ����1-5 �ӱ�׼�����ȡ���ִ�� */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

#define	MAXLINE	4096

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");	/* ��ӡ��ʾ��% */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		buf[strlen(buf)-1] = 0;		/* ��'\n'�滻��'\0' */

		if ((pid=fork()) < 0) {
			fprintf(stderr, "fork error\n");
			exit(1);
		} else if (pid == 0) {	/* �ӽ��� */
			execlp(buf, buf, (char *) 0);	/* ���ִ�гɹ����򲻻᷵�أ����򷵻�-1 */
			printf("%s�޷�ִ��\n", buf);
			exit(127);
		}

		/* ������ */
		if ((pid=waitpid(pid, &status, 0)) < 0) {
			fprintf(stderr, "waitpid error\n");
			exit(2);
		}

		printf("%% ");
	}

	exit(0);
}


