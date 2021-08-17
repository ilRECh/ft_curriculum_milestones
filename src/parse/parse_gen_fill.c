#include "parse.h"

t_parse	*pars_gen_fill(char **argv, unsigned short oper)
{
	t_parse	*pars;

	pars = (t_parse *)malloc(sizeof(t_parse));
	if(!pars)
		exit((short)ret_perr("malloc err -> pars") + 1);
	pars->argv = (char **)malloc(sizeof(char *));
	pars->argv = argv;
	pars->oper = oper;
	return (pars);
}