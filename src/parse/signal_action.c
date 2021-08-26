#include "minishell.h"

void	sig_set(struct sigaction *action, void (f)(int signum, siginfo_t *siginfo, void *code))
{
		action->sa_sigaction = f;
		action->sa_flags = SA_SIGINFO;
		sigaction(SIGINT, action, NULL);
}