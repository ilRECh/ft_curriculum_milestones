#include "minishell.h"

_Bool	ret_perr(const char *mess)
{
	perror(mess);
	return (0);
}