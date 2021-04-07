/* ����2-1 ��ӡ���п��ܵ�sysconf��pathconfֵ */
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("usage: a.out <dirname>");
		exit(1);
	}

	pr_sysconf("ARG_MAX\t\t\t=", _SC_ARG_MAX);	/* exec�����Ĳ�����󳤶�(Byte) */
	pr_sysconf("CHILD_MAX\t\t=", _SC_CHILD_MAX);	/* ÿ��ʵ���û�ID���������� */
	pr_sysconf("clock ticks/second\t=", _SC_CLK_TCK);	/* ÿ��ʱ�ӵδ��� */
	pr_sysconf("NGROUPS_MAX\t\t=", _SC_NGROUPS_MAX);	/* ÿ�����̵����ͬʱ�����ID�� */
	pr_sysconf("OPEN_MAX\t\t=", _SC_OPEN_MAX);	/* ÿ�����������ļ��� */
#ifdef _SC_STREAM_MAX
	pr_sysconf("STREAM_MAX\t\t=", _SC_STREAM_MAX);	/* ����һʱ��ÿ�����̵�����׼I/O���� */
#endif
#ifdef _SC_TZNAME_MAX
	pr_sysconf("TZNAME_MAX\t\t=", _SC_TZNAME_MAX);	/* ʱ�����е�����ֽ��� */
#endif
	pr_sysconf("_POSIX_JOB_CONTROL\t=", _SC_JOB_CONTROL);	/* ָ��ʵ���Ƿ�֧����ҵ���� */
	pr_sysconf("_POSIX_SAVED_IDS\t=", _SC_SAVED_IDS);	 /* ָ��ʵ���Ƿ�֧�ֱ��������-�û�-ID�ͱ��������-��-ID */
	pr_sysconf("_POSIX_VERSION\t\t=", _SC_VERSION);		/* ָ��POSIX.1�汾 */
	pr_pathconf("MAX_CANON\t\t=", "/dev/tty", _PC_MAX_CANON);/* ��һ�ն˹淶������е�����ֽ��� */
	pr_pathconf("MAX_INPUT\t\t=", "/dev/tty", _PC_MAX_INPUT);/* �ն�������п��ÿռ���ֽ��� */
	pr_pathconf("_POSIX_VDISABLE\t\t=", "/dev/tty", _PC_VDISABLE);/* ������,�ն�ר���ַ����ô�ֵ���� */
	pr_pathconf("LINK_MAX\t\t=", argv[1], _PC_LINK_MAX);	/* �ļ������������ֵ */ 
	pr_pathconf("NAME_MAX\t\t=", argv[1], _PC_NAME_MAX); /* �ļ����е�����ֽ���(������'\0') */
	pr_pathconf("PATH_MAX\t\t=", argv[1], _PC_PATH_MAX); /* ���·����������ֽ���(������'\0') */
	pr_pathconf("PIPE_BUF\t\t=", argv[1], _PC_PIPE_BUF); /* ��ԭ�ӵ�д��һ�ܵ�������ֽ��� */
	pr_pathconf("_POSIX_NO_TRUNC\t\t=", argv[1], _PC_NO_TRUNC);  /* ָ����·��������NAME_MAX�Ƿ����һ���� */ 
	pr_pathconf("_POSIX_CHOWN_RESTRICTED\t=", argv[1], _PC_CHOWN_RESTRICTED); /* ָ��ʹ��chown�Ƿ��ܵ����� */

	exit(0);
}

static void pr_sysconf(char *mesg, int name)
{
	long val;

	fputs(mesg, stdout);
	errno = 0;
	if ((val = sysconf(name)) < 0) {
		if (errno != 0) {
			perror("sysconf error");
			exit(1);
		}
		fputs(" (not defined)\n", stdout);
	} else
		printf(" %ld\n", val);
}

static void pr_pathconf(char *mesg, char *path, int name)
{
	long val;

	fputs(mesg, stdout);
	errno = 0;
	if ((val = pathconf(path, name)) < 0) {
		if (errno != 0) {
			fprintf(stderr, "pathconf error, path = %s", path);
			exit(1);
		}
		fputs(" (no limit)\n", stdout);
	} else
		printf(" %ld\n", val);
}
			
			
