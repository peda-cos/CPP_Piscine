#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>

const std::string BitcoinExchange::kDatabasePath = "data.csv";

BitcoinExchange::BitcoinExchange()
{
	loadRateDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rateByDate(other._rateByDate)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_rateByDate = other._rateByDate;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadRateDatabase()
{
	std::ifstream file(kDatabasePath.c_str());
	if (!file.is_open())
	{
		throw FileOpenException();
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::size_t commaPosition = line.find(',');
		if (commaPosition == std::string::npos)
		{
			continue;
		}

		std::string dateText = line.substr(0, commaPosition);
		std::string rateText = line.substr(commaPosition + 1);

		char* parseEnd = NULL;
		double rate = std::strtod(rateText.c_str(), &parseEnd);
		if (*parseEnd != '\0' && *parseEnd != '\r' && *parseEnd != '\n')
		{
			continue;
		}

		_rateByDate[dateText] = rate;
	}
	file.close();
}

std::string BitcoinExchange::trimWhitespace(const std::string& text) const
{
	std::size_t first = text.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
	{
		return "";
	}
	std::size_t last = text.find_last_not_of(" \t\r\n");
	return text.substr(first, last - first + 1);
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::hasValidDateFormat(const std::string& date) const
{
	if (date.length() != 10)
	{
		return false;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		return false;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
		{
			continue;
		}
		if (date[i] < '0' || date[i] > '9')
		{
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (!hasValidDateFormat(date))
	{
		return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
	{
		return false;
	}
	if (day < 1)
	{
		return false;
	}

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
	{
		daysInMonth[2] = 29;
	}

	if (day > daysInMonth[month])
	{
		return false;
	}

	return true;
}

double BitcoinExchange::findExchangeRateForDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _rateByDate.find(date);
	if (it != _rateByDate.end())
	{
		return it->second;
	}

	it = _rateByDate.lower_bound(date);
	if (it == _rateByDate.begin())
	{
		throw DateTooEarlyException();
	}
	--it;
	return it->second;
}

void BitcoinExchange::processInputLine(const std::string& line) const
{
	std::size_t pipePosition = line.find('|');
	if (pipePosition == std::string::npos)
	{
		throw InvalidDateException(line);
	}

	std::string dateText = trimWhitespace(line.substr(0, pipePosition));
	std::string valueText = trimWhitespace(line.substr(pipePosition + 1));

	if (!isValidDate(dateText))
	{
		throw InvalidDateException(line);
	}

	if (valueText.empty())
	{
		throw InvalidDateException(line);
	}

	char* parseEnd = NULL;
	double value = std::strtod(valueText.c_str(), &parseEnd);
	if (*parseEnd != '\0')
	{
		throw InvalidDateException(line);
	}

	if (value < 0)
	{
		throw NegativeValueException();
	}

	if (value > 1000)
	{
		throw ValueTooLargeException();
	}

	double exchangeRate = findExchangeRateForDate(dateText);
	double result = value * exchangeRate;

	std::cout << dateText << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw FileOpenException();
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			std::string trimmedLine = trimWhitespace(line);
			if (trimmedLine == "date | value" || trimmedLine.empty())
			{
				continue;
			}
		}

		if (trimWhitespace(line).empty())
		{
			continue;
		}

		try
		{
			processInputLine(line);
		}
		catch (const InvalidDateException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const NegativeValueException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const ValueTooLargeException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const DateTooEarlyException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}

const char* BitcoinExchange::FileOpenException::what() const throw()
{
	return "Error: could not open file.";
}

BitcoinExchange::InvalidDateException::InvalidDateException(const std::string& input)
	: _message("Error: bad input => " + input)
{
}

BitcoinExchange::InvalidDateException::~InvalidDateException() throw()
{
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return _message.c_str();
}

const char* BitcoinExchange::NegativeValueException::what() const throw()
{
	return "Error: not a positive number.";
}

const char* BitcoinExchange::ValueTooLargeException::what() const throw()
{
	return "Error: too large a number.";
}

const char* BitcoinExchange::DateTooEarlyException::what() const throw()
{
	return "Error: date is before database records.";
}
