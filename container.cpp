/**
 * @ Author: AbderraHman El Haddad Asofi (4reha)
 * @ Create Time: 2022-10-02 16:23:29
 * @ Modified by: AbderraHman El Haddad Asofi (4reha)
 * @ Modified time: 2022-10-02 17:40:36
 * @ Description:
 */

#include <iostream>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

char*	stack_memory()	{
	int stack_size = 65536;
	char *stack = new char[stack_size];

	if (!stack)	{
		std::cout << "Stack memory allocation failed" << std::endl;
		exit(1);
	}
	return (stack + stack_size);
}

int jail(void	*args)	{
	std::cout << "jail called" << std::endl;
	return (0);
}

int	main(void)	{
	std::cout << "Hello World!" << std::endl;
	clone(jail, stack_memory(), SIGCHLD, 0);
    return (0);
}