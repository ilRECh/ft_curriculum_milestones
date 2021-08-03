#include "libft.h"

//  0 = no free, 1 = s1 free, 2 = s2 free, 3 = s1 & s2 free;
char *ft_strjoin_free(char *s1, char *s2, short fr)
{
    char    *res;

    res = ft_strjoin(s1, s2);
    if (fr == 1 || fr == 3)
        free(s1);
    if(fr == 2 || fr == 3)
        free(s2);
    return(res);
}