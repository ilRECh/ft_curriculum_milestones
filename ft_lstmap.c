#include "libft.h"

t_slist	*ft_lstmap(t_slist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_slist	*new_lst;
	t_slist	*tmp;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(NULL);
	tmp = new_lst;
	while (lst)
	{
		tmp->content = (*f)(lst->content);
		if (del)
			(*del)(lst->content);
		if (lst->next)
			tmp->next = ft_lstnew(NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_lst);
}
