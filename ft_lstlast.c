#include "libft.h"

t_slist	*ft_lstlast(t_slist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
