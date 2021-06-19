#include "libft.h"

void	ft_lstadd_front(t_slist **lst, t_slist *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
