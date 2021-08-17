#include "panel.h"

void	skip_quotation(char **ln)
{
	if (**ln == '\"' && *(*ln - 1) != '\\')
	{
		while (*++(*ln) != '\"' || *(*ln - 1) == '\\')
			;
		++(*ln);
	}
	if (**ln == '\'' && *(*ln - 1) != '\\')
	{
		while (*++(*ln) != '\'' || *(*ln - 1) == '\\')
			;
		++(*ln);
	}
}

_Bool	skip_open_case(char **ln)
{
	int	cnt_case;

	cnt_case = 1;
	while (*++(*ln) && cnt_case)
	{
		skip_quotation(ln);
		if (**ln == ')')
			cnt_case--;
		else if (**ln == '(')
			cnt_case++;
	}
	if (cnt_case)
		return (FALSE);
	return (TRUE);
}