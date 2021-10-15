#include "libft.h"

char	**ft_lst_to_char(t_dlist *lst)
{
	t_dlist	*tmp;
	char	**ret;
	int		lenfix;
	int		len;

	tmp = lst;
	if (!lst || !lst->content)
		return (NULL);
	lenfix = (len = ft_lstsizeD(lst)) - 1;
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = NULL;
	while (len--)
	{
		if (!tmp->content)
			return (NULL);
		ret[lenfix - len] = tmp->content;
		tmp = tmp->next;
	}
	return (ret);
}