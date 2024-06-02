#include "push_swap.h"

void	index_check(int smaller, int bigger,
			t_list to_check, t_merge_conf *cur)
{
	if (smaller >= 0 && smaller + 1 <= ft_lstsize(to_check) / 2)
	{
		cur->steps_a = smaller + 1;
		cur->dir_a = ROTATE;
	}
	else if (smaller >= 0)
	{
		cur->steps_a = ft_lstsize(to_check) - smaller - 1;
		cur->dir_a = REVERSE_ROTATE;
	}
	else if (bigger >= 0 && bigger <= ft_lstsize(to_check) / 2)
	{
		cur->steps_a = bigger;
		cur->dir_a = ROTATE * !(!bigger) + NO_DIR * (!bigger);
	}
	else if (bigger >= 0)
	{
		cur->steps_a = ft_lstsize(to_check) - bigger;
		cur->dir_a = REVERSE_ROTATE;
	}
}
