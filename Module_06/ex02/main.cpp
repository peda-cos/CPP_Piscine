#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void) {
	int random = std::rand() % 3;
	switch (random) {
		case 0:
			std::cout << "Generated: A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated: B" << std::endl;
			return new B();
		default:
			std::cout << "Generated: C" << std::endl;
			return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception&) {}
}

int main() {
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++) {
		std::cout << "--- Test " << i + 1 << " ---" << std::endl;
		Base* ptr = generate();

		std::cout << "Identify by pointer: ";
		identify(ptr);

		std::cout << "Identify by reference: ";
		identify(*ptr);

		delete ptr;
		std::cout << std::endl;
	}

	return 0;
}
