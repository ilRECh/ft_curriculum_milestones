#include "libft.h"

void	ft_lst_init(int args, ...)
{
	va_list	arg;
	t_list	*lst;

	va_start(arg, args);
	while (args-- > 0)
	{
		lst = va_arg(arg, t_list *);
		lst->head = NULL;
		lst->cur = NULL;
		lst->end = NULL;
	}
	va_end(arg);
}
