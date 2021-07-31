#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[], char *env[])
{
	char *str = "echo \\s \\\' \"hello\\;\" \'";
	printf("%s\n", str);
	return (0);
}
