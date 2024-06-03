#include <string>

int	HashIt(std::string sTmp)
{
	int	lcl_nLength = sTmp.length();
	int	i = 0;
	int	sum = 0;

	for (; i < lcl_nLength; ++i)
	{
		sum += sTmp[i] * i;
	}
	return (sum + lcl_nLength);
}
