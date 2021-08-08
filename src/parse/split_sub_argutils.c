#include "parse.h"

int     skip_quote(char *str, int *k, char quote, char is_slash)
{
    int i;

    i = (*k) + 1;
    if (is_slash)
        while ((str[++i] && str[i] != quote) || 
        (str[i] == quote && str[i -1] == is_slash))
            ;
    else
        while ((str[++i] && str[i] != quote))
            ;
    return (*k = i + 1);
}

int     ft_strlenspace(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != ' ')
    {
        i++;
        if (str[i] == '\"')
            skip_quote(str, &i, '\"', '\\');
        if (str[i] == '\'')
            skip_quote(str, &i, '\'', FALSE);
    }
    return (i);
}

void    remove_quotation(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        if (ft_strchr("\'\"", str[i]))
            ft_memmove(&str[i], &str[i + 1], ft_strlen(&str[i]));
    
}

void    remove_quotation_tab(char **tabs)
{
    if (!tabs)
        return ;
    while (*tabs)
        remove_quotation(*tabs++);
    
}

void    to_separate_util_args(t_parse *parse, char **tmp)
{
    char    **beg;
    int     i;

    i = 0;
    free(parse->util);
    parse->util = NULL;
    beg = tmp;
    if (*beg && is_file_exists(*beg))
        parse->util = *beg++;
    remove_quotation_tab(beg);
    parse->argv = beg;

}

t_parse  *sub_parse(t_parse *tosub_pars)
{
    t_list  *lst;
    char    **tmp;
    char    *str;
    int     t;
    int     i;

    t = 0;
    i = -1;
    lst = ft_calloc(sizeof(t_list), 1);
    str = tosub_pars->util;
    tmp = (char **)malloc(sizeof(char *) * 1000);   // малочу с запасом (0-й пойдет на util)
    while (TRUE)
    {
        ++i;
        if (str[i] == '\"')
            skip_quote(str, &i, '\"', '\\');
        if (str[i] == '\'')
            skip_quote(str, &i, '\'', FALSE);
        if (!str[i] || str[i] == ' ')
        {
            tmp[t++] = ft_strndup(str, i);
            if (!str[i])
                break ;
            str += i;
            while (*(str) && *(str) == ' ')
                str++;
            i = -1;
        }
    }
    tmp[t] = NULL;
    to_separate_util_args(tosub_pars, tmp);
    return (tosub_pars);
}


t_list	*split_sub_argutils(t_list *lst)
{
    lst->cur = lst->head;

    while (lst->cur)
    {
        lst->cur->content = sub_parse((t_parse *)lst->cur->content);
        lst->cur = lst->cur->next;
    }
    return (lst);
}
