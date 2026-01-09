#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>

const std::string BitcoinExchange::DATABASE_PATH = "data.csv";

BitcoinExchange::BitcoinExchange()
{
	loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase()
{
	std::ifstream file(DATABASE_PATH.c_str());
	if (!file.is_open())
	{
		throw FileOpenException();
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
		{
			continue;
		}

		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

		char* endPtr;
		double rate = std::strtod(rateStr.c_str(), &endPtr);
		if (*endPtr != '\0' && *endPtr != '\r' && *endPtr != '\n')
		{
			continue;
		}

		_database[date] = rate;
	}
	file.close();
}

std::string BitcoinExchange::trim(const std::string& str) const
{
	std::size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
	{
		return "";
	}
	std::size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) const
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
	if (!isValidDateFormat(date))
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

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _database.find(date);
	if (it != _database.end())
	{
		return it->second;
	}

	it = _database.lower_bound(date);
	if (it == _database.begin())
	{
		throw DateTooEarlyException();
	}
	--it;
	return it->second;
}

void BitcoinExchange::parseLine(const std::string& line) const
{
	std::size_t pipePos = line.find('|');
	if (pipePos == std::string::npos)
	{
		throw InvalidDateException(line);
	}

	std::string date = trim(line.substr(0, pipePos));
	std::string valueStr = trim(line.substr(pipePos + 1));

	if (!isValidDate(date))
	{
		throw InvalidDateException(line);
	}

	if (valueStr.empty())
	{
		throw InvalidDateException(line);
	}

	char* endPtr;
	double value = std::strtod(valueStr.c_str(), &endPtr);
	if (*endPtr != '\0')
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

	double rate = getExchangeRate(date);
	double result = value * rate;

	std::cout << date << " => " << value << " = " << result << std::endl;
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
			std::string trimmedLine = trim(line);
			if (trimmedLine == "date | value" || trimmedLine.empty())
			{
				continue;
			}
		}

		if (trim(line).empty())
		{
			continue;
		}

		try
		{
			parseLine(line);
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
