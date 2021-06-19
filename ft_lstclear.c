#include "libft.h"

void	ft_lstclear(t_slist **lst, void (*del)(void *))
{
	t_slist	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		(*del)((*lst)->content);
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
