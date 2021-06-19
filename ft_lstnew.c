#include "libft.h"

t_slist	*ft_lstnew(void *content)
{
	t_slist	*new_elem;

	new_elem = (t_slist *)ft_calloc(1, sizeof(t_slist));
	if (new_elem)
		new_elem->content = content;
	return (new_elem);
}
