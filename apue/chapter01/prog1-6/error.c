/* ����1-6 ��ʾstrerror��perror */
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));

	errno = ENOENT;
	perror(argv[0]);

	exit(0);
}
