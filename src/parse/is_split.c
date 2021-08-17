#include "parse.h"

short	is_split(char *str)
{
	if (!str || !*(str) || *(str - 1) == '\\')
		return (0);
	if (*(str) == '(' && *(str - 2) != '\\')
		return (CASE_OPEN);
	if (*(str) == ')' && *(str - 2) != '\\')
		return (CASE_CLOSE);
	if (*(str) == *(str + 1))
	{
		if (*(str) == '&')
			return (AND);
		if (*(str) == '|')
			return(OR);
		if (*(str) == '<')
			return(RDCT_L2);
		if (*(str) == '>')
			return(RDCT_R2);
	}
	if (*(str) == ';')
		return (END);
	if(*(str) == '|')
		return (PIPE);
	if (*(str) == '<')
		return(RDCT_L);
	if (*(str) == '>')
		return(RDCT_R);
	return(FALSE);
}