#include "libft.h"

void	ft_lstdelone(t_slist *lst, void (*del)(void *))
{
	if (lst)
		(*del)(lst->content);
	free(lst);
}
