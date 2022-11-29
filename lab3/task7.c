#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int pid, pid1, pid2;
	pid = fork();
	if (pid == 0) {

		printf("parent process id %d\n",
			getpid());
	}
	else {
		pid1 = fork();
		if (pid1 == 0) {
			printf("child process id %d\n",
			getpid());
		}
		else {
			pid2 = fork();
			if (pid2 == 0) {
				printf("grandchild process id %d\n",
			getpid());
			}
			else {
				printf("grandchild process id %d\n",
			getpid());
			}
		}
	}

	return 0;
}
