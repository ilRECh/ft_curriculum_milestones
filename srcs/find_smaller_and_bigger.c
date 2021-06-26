#include "push_swap.h"

typedef struct s_search
{
	int		smaller;
	int		bigger;
	int		*index_smaller;
	int		*index_bigger;
	t_list	to_search;
}	t_search;

static void	searching(t_search search)
{
	while (TRUE)
	{
		if (((t_content *)search.to_search.cur->content)->order == search.smaller)
			*search.index_smaller = ft_lstindex(search.to_search);
		else if (((t_content *)search.to_search.cur->content)->order == search.bigger)
			*search.index_bigger = ft_lstindex(search.to_search);
		search.to_search.cur = search.to_search.cur->next;
		if (search.to_search.cur->prev == search.to_search.end)
			break ;
	}
}

void	find_smaller_and_bigger(int *index_smaller, int *index_bigger,
				int order, t_list to_search)
{
	t_search	search;

	search.to_search = to_search;
	search.index_bigger = index_bigger;
	search.index_smaller = index_smaller;
	search.smaller = order - 1;
	search.bigger = order + 1;
	*search.index_smaller = -1;
	*search.index_bigger = -1;
	if (ft_lstsize(to_search) > 1)
	{
		while (*search.index_smaller < 0 && *search.index_bigger < 0)
		{
			search.to_search.cur = search.to_search.head;
			searching(search);
			if (*search.index_bigger < 0)
				search.bigger += 1;
			if (*search.index_smaller < 0)
				search.smaller -= 1;
		}
	}
}