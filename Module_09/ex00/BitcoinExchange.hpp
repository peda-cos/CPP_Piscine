#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <exception>

class BitcoinExchange
{
private:
	std::map<std::string, double> _rateByDate;
	static const std::string kDatabasePath;

	void loadRateDatabase();
	bool hasValidDateFormat(const std::string& date) const;
	bool isValidDate(const std::string& date) const;
	bool isLeapYear(int year) const;
	double findExchangeRateForDate(const std::string& date) const;
	void processInputLine(const std::string& line) const;
	std::string trimWhitespace(const std::string& text) const;

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
