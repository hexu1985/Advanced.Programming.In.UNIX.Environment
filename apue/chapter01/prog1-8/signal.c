/* ����1-5 �ӱ�׼�����ȡ���ִ�� */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

#define	MAXLINE	4096

static void sig_int(int);		/* �Զ�����źŲ�׽���� */

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR) {
		perror("signal error");
		exit(1);
	}

	printf("%% ");	/* ��ӡ��ʾ��% */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		buf[strlen(buf)-1] = 0;		/* ��'\n'�滻��'\0' */

		if ((pid=fork()) < 0) {
			perror("fork error");
			exit(1);
		} else if (pid == 0) {	/* �ӽ��� */
			execlp(buf, buf, (char *) 0);	/* ���ִ�гɹ����򲻻᷵�أ����򷵻�-1 */
			printf("%s�޷�ִ��\n", buf);
			exit(127);
		}

		/* ������ */
		if ((pid=waitpid(pid, &status, 0)) < 0) {
			fprintf(stderr, "waitpid error\n");
			exit(1);
		}

		printf("%% ");
	}

	exit(0);
}

void sig_int(int signo) 
{
	printf("interrupt\n%% ");
}
