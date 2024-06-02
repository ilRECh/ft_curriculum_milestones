#include "libft.h"

t_list	*ft_lstnew(uint64_t value)
{
	t_list	*new_elem;

	new_elem = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new_elem)
		new_elem->value = value;
	return (new_elem);
}
