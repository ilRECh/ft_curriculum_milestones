#include "replace.hpp"

//	IFS: stream to read from
//	sTmp string to place the result in
int	GetStringFromStream(std::ifstream &IFS, std::string &sTmp)
{
	char	*buf;
	size_t	FileSize = IFS.tellg();
	IFS.seekg(0, std::ios::beg);
	buf = new char[FileSize + 1];
	buf[FileSize] = 0;
	if (!IFS.read(buf, FileSize))
	{
		std::cout << "cannot read from input file" << std::endl;
		return (1);
	}
	sTmp = buf;
	delete [] buf;
	return (0);
}

int	PutReplaceToStream(std::ofstream &IFS, std::string &sTmp, std::string &sS1, std::string &sS2)
{
	std::string	lcl_sTmp;
	size_t	lcl_CurrentPos = 0;
	size_t	lcl_PreviousCurrentPos = 0;
	size_t	sS1length = sS1.length();

	while (true)
	{
		lcl_CurrentPos = sTmp.find(sS1, lcl_CurrentPos);
		if (lcl_CurrentPos != std::string::npos)
		{
			lcl_sTmp += sTmp.substr(lcl_PreviousCurrentPos, lcl_CurrentPos - lcl_PreviousCurrentPos);
			lcl_sTmp += sS2;
			lcl_PreviousCurrentPos = lcl_CurrentPos + sS1length;
		}
		else
		{
			lcl_sTmp += sTmp.substr(lcl_PreviousCurrentPos, sTmp.length() - lcl_PreviousCurrentPos);
			break ;
		}
		lcl_CurrentPos += sS1length;
	}
	if (!(IFS << lcl_sTmp))
	{
		std::cout << "cannot write to output file" << std::endl;
		return (1);
	}
	return (0);
}

int	replace(std::string sFilename, std::string sS1, std::string sS2)
{
	if (sS1.empty() || sS2.empty())
	{
		std::cout << "s1 and s2 cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream	IFS(sFilename, std::ios::in | std::ios::binary | std::ios::ate);

	if (IFS.fail())
	{
		std::cout << "cannot open input file: " << sFilename << std::endl;
		return (1);
	}

	std::string	sTmp;

	if (GetStringFromStream(IFS, sTmp))
	{
		IFS.close();
		return (1);
	}
	IFS.close();

	std::ofstream	OFS(sFilename + ".replace", std::ios::out | std::ios::trunc | std::ios::binary);
	
	if (OFS.fail())
	{
		std::cout << "cannot open output file: " << sFilename + ".replace" << std::endl;
		return (1);
	}
	return ((PutReplaceToStream(OFS, sTmp, sS1, sS2)) ? (OFS.close(), 1) : (OFS.close(), 0));
}
