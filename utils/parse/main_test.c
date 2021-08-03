#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*get_command_line(char **line, char **env);

int main(int argc, char const *argv[], char *env[])
{
	// char	***tabs;

	//	\\	\+
	//			echo \s \' "hello\;" '
	// char *str = ft_strdup("\'\\\'echo \\s \\\' \' \"hello\\;\" \'");
	// char *str = ft_strdup("echo \"h\\\"ello;\" \'to go\'; echo \"hello;\" \'to go\'");
	// char *str = ft_strdup("'to;' >> t; echo; 'hii'");
	char *str = ft_strdup("echo \"$PWD kkk00;00\" > a > b;echo \"00;00\" > a > b");
	// char *str = ft_strdup(*++argv);
	printf("%s\n\n", str);
	get_command_line(&str, env);
	return (0);
}
