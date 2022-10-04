#include <iostream>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <sys/wait.h>

char*	stack_memory()	{
	int stack_size = 50000;
	char *stack = new char[stack_size];

	if (!stack)	{
		std::cout << "Stack memory allocation failed" << std::endl;
		exit(1);
	}
	return (stack + stack_size);
}

int jail(void	*args)	{

	std::cout << "jail called" << std::endl;
	char **cmd = (char **)args;
	chroot("./fake_root");
	chdir("/");
	mount("proc", "/proc", "proc", 0, 0);
	if (!fork())
		execve(cmd[0], cmd, NULL);
	wait(NULL);
	umount("/proc");
	return (0);
}

int	main(int ac, char** av)	{
	std::cout << "Hello World!" << std::endl;
	clone(jail, stack_memory(), CLONE_NEWUTS | CLONE_NEWPID | SIGCHLD, &av[1]);
	wait(NULL);

    return (0);
}