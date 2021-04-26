#include "parser.h"

void char_print(char c, int *total)
{
	write(1, &c, 1);
	*total += 1;
}
