#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*get_command_line(char *line);

int main(int argc, char const *argv[], char *env[])
{
	char	***tabs;
	int		a, b;

	a = b = -1;
	//	\\	\+
	//			echo \s \' "hello\;" '
	char *str = "echo \\s \\\' \"hello\\;\" \'";
	printf("%s\n\n", str);
	get_command_line(str);
	return (0);
}
