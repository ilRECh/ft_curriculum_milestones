#include "libft.h"

t_dlist	*ft_lstnew(void *content)
{
	t_dlist	*new_elem;

	new_elem = (t_dlist *)ft_calloc(1, sizeof(t_dlist));
	if (new_elem)
		new_elem->content = content;
	return (new_elem);
}
