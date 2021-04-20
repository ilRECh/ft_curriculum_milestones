#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(NULL);
	tmp = new_lst;
	(void)del;
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
