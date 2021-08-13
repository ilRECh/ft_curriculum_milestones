#include "parse.h"
/*
for find zone
->	yes	| || &&
->	not	< > << >>

skip "" ''
not skip \" \'
*/

unsigned int	skip_quote_byindex(char *line, unsigned int iter)
{
	if (line[iter] == '\"' && line[iter - 1] != '\\')
		while (line[++iter] && (line[iter] != '\"' || line[iter - 1] == '\\'))
			;
	if (line[iter] == '\'' && line[iter - 1] != '\\')
		while (line[++iter] && (line[iter] != '\'' || line[iter - 1] == '\\'))
			;
	return (iter);
}

unsigned int	*find_zone(char *line, unsigned int *zone, char *separ)
{
	// if (!*zone)
	// 	return (zone);
	if (ft_strchr(separ, line[*zone]))
		while (ft_strchr(separ, line[*zone]))
			*zone += 1;
	else
		while (line[(*zone)] && (!ft_strchr(separ, line[*zone]) || line[*zone] == '\\'))
			*zone = skip_quote_byindex(line, (*zone)) + 1;
	return (zone);
}

void	ft_move_util(char *line, unsigned int position, unsigned int lenword)
{
	char	tmp[lenword + 2];

	if (!position)
		return ;
	while (line[position + lenword] && (ft_isprint(line[position + lenword])
		&& (!ft_strchr("|&;<>", line[position + lenword]) || line[position + lenword] == '\\')))
	{
		if (ft_strchr("\"\'", line[position]) && line[position] != '\\')
			lenword = skip_quote_byindex(&line[position], lenword);
		else
			lenword++;
	}
	ft_memmove(&line[position], &line[position], lenword + 1);
	ft_memmove(tmp, &line[position - 1], lenword + 1);
	ft_memmove(&line[lenword + 1], line, position - 1);
	if (ft_strchr("\"\'", *tmp))
	{
		ft_memmove(line, tmp + 1, lenword - 2);
		ft_memset(&line[lenword - 2], ' ', 3);
	}
	else
	{
		ft_memmove(line, tmp, lenword);
		line[lenword] = ' ';
		ft_memmove(line, &line[1], position + lenword - 1);
		line[position + lenword - 1] = ' ';
	}
}

_Bool	search_util(char *line, unsigned int a, unsigned int b)
{
	char			*word;
	char			*fullname;
	unsigned int	this_a;
	unsigned int	this_b;

	if (!line[a])
		return (FALSE);
	this_a = a;
	while (line[this_a] == ' ')
		this_a++;
	this_b = this_a;
	fullname = NULL;
	while (this_a < b)
	{
		find_zone(line, &this_b, " ");
		word = ft_strndup(&line[this_a], this_b - this_a);
		trimmer(word, "\"\'");
		if (ft_strncmp(word, "cat", 3))
			fullname = is_util_exists(word);
		free(word);
		if (fullname)
		{
			free(fullname);
			while(ft_strchr(" ()", line[a]))
				a++;
			ft_move_util(&line[a], this_a - a, this_b - this_a);
		}
		this_a = *find_zone(line, &this_b, " ");
	}
	return(TRUE);
}

void	pre_parser(char *line)
{
	// unsigned int	word_segmnt[2];
	unsigned int	search_zone = 0;

	while (search_util(line, search_zone, *find_zone(line, &search_zone, "|&")))
	{
		find_zone(line, &search_zone, "|&");
	}
}