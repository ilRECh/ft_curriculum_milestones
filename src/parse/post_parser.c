#include "parse.h"

static _Bool	check_cmp(t_dlist *dlst)
{
	if ((((t_parse *)dlst)->argv && !((t_parse *)dlst)->argv[0]) && \
	(!(t_parse *)dlst->prev || !((t_parse *)dlst->prev)->argv || !((t_parse *)dlst->prev)->argv[0]) && \
	!((t_parse *)dlst)->oper)
		return (TRUE);
	return (FALSE);
}

_Bool	post_parser(t_list *lst)
{
	_Bool	is_was_file_redir;

	lst->cur = lst->head;
	is_was_file_redir = FALSE;
	while(lst->cur && !is_was_file_redir)
	{
		is_was_file_redir = check_cmp(lst->cur);
		lst->cur = lst->cur->next;
	}
	if (is_was_file_redir)
	{
		printf("Error: not found %s\n", ((t_parse *)lst->cur)->argv[1]);
		ft_lstclear(lst, free_parse);
	}
	return (is_was_file_redir);
}