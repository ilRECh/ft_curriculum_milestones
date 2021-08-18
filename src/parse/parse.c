/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:48 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/18 06:20:49 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	if_redir(t_wheel *w)
{
	if (w->ln != w->line)
		ft_lstadd_back(
			w->lst,
			pars_gen_fill(
				argv_fill_1(
					trimmer(
						ft_strndup(w->line, w->ln - w->line), " ")),
				w->sp_prev));
	while (*w->ln && ft_strchr("<> ", *++w->ln))
		;
	w->sp_prev = w->sp;
	w->line = w->ln;
}

void	if_pipe_oper_end(t_wheel *w)
{
	if (w->ln != w->line)
		ft_lstadd_back(w->lst,
			pars_gen_fill(
				argv_fill_1(
					trimmer(
						ft_strndup(w->line, w->ln - w->line), " ")),
				w->sp_prev));
	ft_lstadd_back(w->lst, pars_gen_fill((char **) NULL, w->sp));
	while (*w->ln && ft_strchr(";&| ", *++w->ln))
		;
	w->sp_prev = (w->sp = 0);
	w->line = w->ln;
}

void	if_sub_lst(t_wheel *w)
{
	char	**argv;

	if (w->ln != w->line)
		ft_lstadd_back(w->lst,
			pars_gen_fill(
				argv_fill_1(
					trimmer(
						ft_strndup(w->line, w->ln - w->line), " ")),
				w->sp_prev));
	argv = argv_fill_2(ft_strdup(CASE),
			(char *)split_ignore_caps(w->ln + 1, 0));
	ft_lstadd_back(w->lst, pars_gen_fill(argv, 0));
	case_skip(&w->ln);
	while (*w->ln == ' ')
		w->ln++;
	w->sp_prev = w->sp;
	w->line = w->ln;
}

t_list	*if_close_bracket(t_wheel *w)
{
	if (w->ln != w->line)
		ft_lstadd_back(w->lst,
			pars_gen_fill(
				argv_fill_1(
					trimmer(
						ft_strndup(w->line, w->ln - w->line), " ")),
				w->sp_prev));
	return (w->lst);
}

t_list	*split_ignore_caps(char *line, short sp_prev)
{
	t_wheel	w;

	w.sp = 0;
	w.sp_prev = sp_prev;
	while (*line == ' ')
		line++;
	w.ln = line;
	w.line = line;
	w.lst = ft_calloc(1, sizeof(t_list));
	while (*w.ln)
	{
		skip_quotation(&w.ln);
		get_next_sp(&w.ln, &w.sp);
		if (!*w.ln || (w.sp > 0 && w.sp < 5))
			if_redir(&w);
		else if (w.sp > 4 && w.sp < 9)
			if_pipe_oper_end(&w);
		else if (w.sp == 9)
			if_sub_lst(&w);
		else if (w.sp == 10)
			return (if_close_bracket(&w));
	}
	return (w.lst);
}
