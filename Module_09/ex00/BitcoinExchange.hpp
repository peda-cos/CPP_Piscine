#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <exception>

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;
	static const std::string DATABASE_PATH;

	void loadDatabase();
	bool isValidDateFormat(const std::string& date) const;
	bool isValidDate(const std::string& date) const;
	bool isLeapYear(int year) const;
	double getExchangeRate(const std::string& date) const;
	void parseLine(const std::string& line) const;
	std::string trim(const std::string& str) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void processInputFile(const std::string& filename) const;

	class FileOpenException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class InvalidDateException : public std::exception
	{
	private:
		std::string _message;
	public:
		InvalidDateException(const std::string& input);
		virtual ~InvalidDateException() throw();
		const char* what() const throw();
	};

	class NegativeValueException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class ValueTooLargeException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class DateTooEarlyException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif
