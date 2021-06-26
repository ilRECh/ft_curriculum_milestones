#include "libft.h"

void    ft_lst_init(t_list *lst)
{
    lst->head = NULL;
    lst->cur = NULL;
    lst->end = NULL;
}