#include "Converter.hpp"

static const std::string NOT_DISPLAYABLE("Non displayable");
static const std::string IMPOSSIBLE("impossible");

Converter::Converter():	m_nCharValue(),
						m_sCharStatus(),
						m_nIntValue(),
						m_sIntStatus(),
						m_fFloatValue(),
						m_sFloatStatus(),
						m_dDoubleValue(),
						m_sDoubleStatus()
{
}

Converter::~Converter()
{
}

Converter::Converter(const Converter &C):	m_nCharValue(C.m_nCharValue),
											m_sCharStatus(C.m_sCharStatus),
											m_nIntValue(C.m_nIntValue),
											m_sIntStatus(C.m_sIntStatus),
											m_fFloatValue(C.m_fFloatValue),
											m_sFloatStatus(C.m_sFloatStatus),
											m_dDoubleValue(C.m_dDoubleValue),
											m_sDoubleStatus(C.m_sDoubleStatus)
{
}

Converter& Converter::operator=(const Converter &C)
{
	if (this == &C)
		return (*this);
	m_nCharValue = C.m_nCharValue;
	m_sCharStatus = C.m_sCharStatus;
	m_nIntValue = C.m_nIntValue;
	m_sIntStatus = C.m_sIntStatus;
	m_fFloatValue = C.m_fFloatValue;
	m_sFloatStatus = C.m_sFloatStatus;
	m_dDoubleValue = C.m_dDoubleValue;
	m_sDoubleStatus = C.m_sDoubleStatus;
	return (*this);
}

Converter::Converter(char *num):	m_nCharValue(),
									m_sCharStatus(),
									m_nIntValue(),
									m_sIntStatus(),
									m_fFloatValue(),
									m_sFloatStatus(),
									m_dDoubleValue(),
									m_sDoubleStatus()
{
	if (!num)
		throw ShittyNum();
	num = std::strtok(num, " \t\v\n");
	if (!num)
		throw ShittyNum();
	size_t end;
	std::string number = num;
	if (number == "-inff"
		|| number == "+inff"
		|| number == "nanf"
		|| (number.find('f') != number.npos && number.find('f') == number.rfind('f') && number[number.find('f') + 1] == '\0'
			&& number.find('.') != number.npos && number.find('.') == number.rfind('.')))
	{
		m_fFloatValue = std::stof(number, &end);
		if (!(number[end] == 'f' && number[end + 1] == '\0'))
			throw ShittyNum();
		m_dDoubleValue = static_cast<double>(m_fFloatValue);
		if (static_cast<float>(std::numeric_limits<int>::min()) <= m_fFloatValue
			&& m_fFloatValue <= static_cast<float>(std::numeric_limits<int>::max()))
		{
			m_nIntValue = static_cast<int>(m_fFloatValue);
		}
		else
		{
			m_sIntStatus = IMPOSSIBLE;
		}
		if (static_cast<float>(std::numeric_limits<char>::min()) <= m_fFloatValue
			&& m_fFloatValue <= static_cast<float>(std::numeric_limits<char>::max()))
		{
			m_nCharValue = static_cast<char>(m_fFloatValue);
			if (!(m_nCharValue >= 32 && m_nCharValue <= 127))
			{
				m_sCharStatus = NOT_DISPLAYABLE;
			}
		}
		else
		{
			m_sCharStatus = IMPOSSIBLE;
		}
	}
	else if (number == "-inf"
		|| number == "+inf"
		|| number == "nan"
		|| (number.find('.') != number.npos && number.find('.') == number.rfind('.')))
	{
		m_dDoubleValue = std::stod(number, &end);
		if (number[end] != '\0')
			throw ShittyNum();
		if ((static_cast<double>(std::numeric_limits<float>::min()) <= m_dDoubleValue
			&& m_dDoubleValue <= static_cast<double>(std::numeric_limits<float>::max()))
			|| number == "-inf" || number == "+inf" || number == "nan")
		{
			m_fFloatValue = static_cast<float>(m_dDoubleValue);
		}
		else
		{
			m_sFloatStatus = IMPOSSIBLE;
		}
		if (static_cast<double>(std::numeric_limits<int>::min()) <= m_dDoubleValue
			&& m_dDoubleValue <= static_cast<double>(std::numeric_limits<int>::max()))
		{
			m_nIntValue = static_cast<int>(m_dDoubleValue);
		}
		else
		{
			m_sIntStatus = IMPOSSIBLE;
		}
		if (static_cast<double>(std::numeric_limits<char>::min()) <= m_dDoubleValue
			&& m_dDoubleValue <= static_cast<double>(std::numeric_limits<char>::max()))
		{
			m_nCharValue = static_cast<char>(m_dDoubleValue);
			if (!(m_nCharValue >= 32 && m_nCharValue <= 127))
			{
				m_sCharStatus = NOT_DISPLAYABLE;
			}
		}
		else
		{
			m_sCharStatus = IMPOSSIBLE;
		}
	}
	else if (number.size() == 1 && !std::isdigit(number[0]))
	{
		m_nCharValue = number[0];
		if (!(m_nCharValue >= 32 && m_nCharValue <= 127))
		{
			m_sCharStatus = NOT_DISPLAYABLE;
		}
		m_nIntValue = static_cast<int>(m_nCharValue);
		m_fFloatValue = static_cast<float>(m_nCharValue);
		m_dDoubleValue = static_cast<double>(m_nCharValue);
	}
	else
	{
		m_nIntValue = std::stoi(number, &end);
		if (number[end] != '\0')
			throw ShittyNum();
		if (!(m_nIntValue >= 32 && m_nIntValue <= 127))
		{
			m_sCharStatus = NOT_DISPLAYABLE;
		}
		else
		{
			m_nCharValue = static_cast<char>(m_nIntValue);
		}
		m_fFloatValue = static_cast<float>(m_nIntValue);
		m_dDoubleValue = static_cast<double>(m_nIntValue);
	}
}

void Converter::printCharValue() const
{
	std::cout << "char: ";
	if (m_sCharStatus.empty())
	{
		std::cout << '\'' << m_nCharValue << '\'' << std::endl;
	}
	else
	{
		std::cout << m_sCharStatus << std::endl;
	}
}

void Converter::printIntValue() const
{
	std::cout << "int: ";
	if (m_sIntStatus.empty())
	{
		std::cout << m_nIntValue << std::endl;
	}
	else
	{
		std::cout << m_sIntStatus << std::endl;
	}
}

void Converter::printFloatValue() const
{
	std::cout << "float: ";
	if (m_sFloatStatus.empty())
	{
		std::cout << std::setprecision(1) << std::fixed << m_fFloatValue << 'f' << std::endl;
	}
	else
	{
		std::cout << m_sFloatStatus << std::endl;
	}
}

void Converter::printDoubleValue() const
{
	std::cout << "double: ";
	if (m_sDoubleStatus.empty())
	{
		std::cout << std::setprecision(1) << std::fixed << m_dDoubleValue << std::endl;
	}
	else
	{
		std::cout << m_sDoubleStatus << std::endl;
	}
}

const char* Converter::ShittyNum::what() const throw()
{
	return ("Why are you geh?");
}
