#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new_elem)
		new_elem->content = content;
	return (new_elem);
}
