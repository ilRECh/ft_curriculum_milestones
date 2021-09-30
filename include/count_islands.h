#pragma once

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h" 

typedef struct s_islands
{
	char	**map;
}	t_islands;

bool	count(char *map);
