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
    char    *beg;
    int     i;

    i = 0;
    beg = is_util_exists(trimmer(*tmp, "\"\'"));
    // parse->util = *tmp;
    if (beg)
    {
        free(*tmp);
        *tmp = beg;
    }
    else
    {
        tmp[1] = tmp[0];
        tmp[0] = NULL;
    }
    remove_quotation_tab(tmp + 1);
    parse->argv = tmp;

}

t_parse  *sub_parse(t_parse *tosub_pars)
{
    char    **tmp;
    char    *str;
    int     t;
    int     i;

    t = 0;
    i = -1;
    str = *(tosub_pars->argv);
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
    free(*(tosub_pars->argv));
    free((tosub_pars->argv));
    to_separate_util_args(tosub_pars, tmp);
    return (tosub_pars);
}


t_list	*split_sub_argutils(t_list *lst)
{
    t_parse *parse;

    // char **tmp;
    // t_parse *p;

    lst->cur = lst->head;
    while (lst->cur)
    {
        parse = (t_parse *)lst->cur->content;
        if (*parse->argv && !(parse->oper > 4 && parse->oper < 9) && !ft_strncmp(CASE, *parse->argv, ft_strlen(CASE)))
            split_sub_argutils(((t_list *)((t_parse *)lst->cur->content)->argv[1]));
        else if (*parse->argv && !(parse->oper > 4 && parse->oper < 9))
            lst->cur->content = sub_parse(parse);

        // tmp = parse->argv;
        // if (parse->oper < 5)
        // {
        //     write(1, tmp[0], ft_strlen(tmp[0]));
        //     write(1, "\n", 1);
        //     write(1, tmp[1], ft_strlen(tmp[1]));
        //     write(1, "\n", 1);
        // }
        lst->cur = lst->cur->next;
    }
    return (lst);
}
