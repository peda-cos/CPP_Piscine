#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.id = 42;
	data.name = "test";
	data.value = 3.14;

	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Data contents: id=" << data.id << ", name=" << data.name
			  << ", value=" << data.value << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << deserialized << std::endl;

	if (deserialized == &data) {
		std::cout << "SUCCESS: Pointers match!" << std::endl;
		std::cout << "Deserialized contents: id=" << deserialized->id
				  << ", name=" << deserialized->name
				  << ", value=" << deserialized->value << std::endl;
	} else {
		std::cout << "FAILURE: Pointers do not match!" << std::endl;
	}

	return 0;
}
