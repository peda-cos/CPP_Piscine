/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:30:00 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/05 23:50:56 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter {
  private:
    // Orthodox Canonical Form - all private to prevent instantiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    // Helper methods for type detection
    static bool isCharLiteral(const std::string &str);
    static bool isIntLiteral(const std::string &str);
    static bool isFloatLiteral(const std::string &str);
    static bool isDoubleLiteral(const std::string &str);
    static bool isPseudoLiteral(const std::string &str);

    // Conversion helpers
    static void convertFromChar(char c);
    static void convertFromInt(long value);
    static void convertFromFloat(float value);
    static void convertFromDouble(double value);
    static void convertPseudoLiteral(const std::string &str);

    // Display helpers
    static void displayChar(double value, bool impossible);
    static void displayInt(double value, bool impossible);
    static void displayFloat(double value, bool impossible);
    static void displayDouble(double value, bool impossible);

  public:
    static void convert(const std::string &literal);
};

#endif
