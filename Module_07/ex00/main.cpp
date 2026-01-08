#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << std::endl << "--- Additional tests ---" << std::endl;

	int x = 5;
	int y = 5;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min(x, y) << " (returns second when equal)" << std::endl;
	std::cout << "max( x, y ) = " << ::max(x, y) << " (returns second when equal)" << std::endl;

	double p = 3.14;
	double q = 2.71;
	::swap(p, q);
	std::cout << "After swap: p = " << p << ", q = " << q << std::endl;

	return 0;
}
