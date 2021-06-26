#include "libft.h"

int ft_lstindex(t_list lst)
{
    int index;

    index = 0;
    while (lst.head != lst.cur)
    {
        lst.head = lst.head->next;
        index++;
    }
    return (index);
}
