#include "push_swap.h"

void	clear_keep(t_list to_clear)
{
	((t_content *)to_clear.cur->content)->keep = FALSE;
}
