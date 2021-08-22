#include "parse.h"

_Bool	post_parser(t_list *lst)
{
	_Bool	is_was_file_redir;
	t_parse	*parse;

	lst->cur = lst->head;
	is_was_file_redir = FALSE;
	while(lst->cur && !is_was_file_redir)
	{
		parse = lst->cur->content;
		if (parse->argv && !parse->argv[0] && parse->argv[1] && !parse->oper)
			is_was_file_redir = TRUE;
		lst->cur = lst->cur->next;
	}
	if (is_was_file_redir)
	{
		printf("Error: not found %s\n", parse->argv[1]);
		ft_lstclear(lst, free_parse);
	}
	return (is_was_file_redir);
}