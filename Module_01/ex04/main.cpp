/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:41:29 by peda-cos          #+#    #+#             */
/*   Updated: 2025/07/31 15:52:39 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string replaceAll(const std::string &str, const std::string &from,
	const std::string &to)
{
	size_t	start_pos;
	size_t	pos;

	std::string result;
	start_pos = 0;
	if (from.empty())
		return (str);
	while ((pos = str.find(from, start_pos)) != std::string::npos)
	{
		result += str.substr(start_pos, pos - start_pos);
		result += to;
		start_pos = pos + from.length();
	}
	result += str.substr(start_pos);
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: wrong number of arguments.\n";
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>\n";
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: string to replace cannot be empty.\n";
		return (1);
	}
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: could not open file '" << filename << "'.\n";
		return (1);
	}
	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: could not create file '" << outFilename << "'.\n";
		inFile.close();
		return (1);
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		std::string modifiedLine = replaceAll(line, s1, s2);
		outFile << modifiedLine;
		if (!inFile.eof())
			outFile << "\n";
	}
	inFile.close();
	outFile.close();
	std::cout << "Replacement completed. Output written to '" << outFilename << "'.\n";
	return (0);
}
