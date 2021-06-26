#include "libft.h"

t_list	ft_lstmap(t_list lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	new_lst;

	ft_lst_init(&new_lst);
	if (!f)
		return (new_lst);
	lst.cur = lst.head;
	while (TRUE)
	{
		ft_lstadd_back(&new_lst, (*f)(lst.cur->content));
		if (del)
			(*del)(lst.cur->content);
		if (lst.cur->next == lst.head)
			break ;
		lst.cur = lst.cur->next;
		new_lst.cur = new_lst.cur->next;
	}
	return (new_lst);
}