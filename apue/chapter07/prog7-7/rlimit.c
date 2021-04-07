/* ����7-7 ��ӡ��ǰ��Դ���� */
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

#define doit(name)	pr_limits(#name, name)

static void pr_limits(char *, int);

int main(void)
{
	doit(RLIMIT_CORE);
	doit(RLIMIT_CPU);
	doit(RLIMIT_DATA);
	doit(RLIMIT_FSIZE);

#ifdef	RLIMIT_MEMLOCK	
	doit(RLIMIT_MEMLOCK);
#endif
#ifdef	RLIMIT_NOFILE		/* SVR4 name */	
	doit(RLIMIT_NOFILE);
#endif
#ifdef	RLIMIT_OFILE		/* 4.3+BSD name */	
	doit(RLIMIT_OFILE);
#endif
#ifdef	RLIMIT_NPROC	
	doit(RLIMIT_NPROC);
#endif
#ifdef	RLIMIT_RSS	
	doit(RLIMIT_RSS);
#endif
	doit(RLIMIT_STACK);
#ifdef	RLIMIT_VMEM	
	doit(RLIMIT_VMEM);
#endif

	exit(0);
}

static void pr_limits(char *name, int resource)
{
	struct rlimit limit;

	if (getrlimit(resource, &limit) < 0) {
		fprintf(stderr, "getrlimit error for %s", name);
		exit(1);
	}
	printf("%-14s  ", name);
	if (limit.rlim_cur == RLIM_INFINITY)
		printf("(infinite)  ");
	else
		printf("%10ld  ", limit.rlim_cur);
	if (limit.rlim_max == RLIM_INFINITY)
		printf("(nfinite)\n");
	else
		printf("%10ld\n", limit.rlim_max);
}