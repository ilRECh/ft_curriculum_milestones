#include "pipex.h"

static inline void	usage(void)
{
	write(1, "\n\tusage: " 
		CYAN "./pipex <fileIN> <cmd1> <cmd2> <fileOUT>\n\n" RESET, 59);
}

int main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		usage();
	else
		pipex(argc, argv, envp);
	return (0);
}
