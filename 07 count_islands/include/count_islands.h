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
	int 	height;
	int 	length;
}	t_islands;

bool	count_islands(t_islands *islands);
bool	parse(char *map, t_islands *islands);
