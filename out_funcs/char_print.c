#include "parser.h"

//but it must return amount of symbols it has printed
void char_print(char c, int *total)
{
	write(1, &c, 1);
	*total += 1;
}
