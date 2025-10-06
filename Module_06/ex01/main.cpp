/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 00:24:17 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/06 00:30:14 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iomanip>
#include <iostream>

int main() {
    Data originalData;
    originalData.id = 42;
    originalData.name = "Test Data";
    originalData.value = 3.14159;

    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << "ID: " << originalData.id << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Value: " << std::fixed << std::setprecision(5)
	      << originalData.value << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "=== Serialization ===" << std::endl;
    std::cout << "Serialized value: 0x" << std::hex << serialized << std::dec
	      << std::endl;
    std::cout << std::endl;

    Data *deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "=== Deserialization ===" << std::endl;
    std::cout << "Deserialized address: " << deserializedPtr << std::endl;
    std::cout << std::endl;

    std::cout << "=== Verification ===" << std::endl;
    if (deserializedPtr == &originalData) {
	std::cout << "✓ Pointers are equal!" << std::endl;
    } else {
	std::cout << "✗ Pointers are NOT equal!" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Deserialized Data ===" << std::endl;
    std::cout << "ID: " << deserializedPtr->id << std::endl;
    std::cout << "Name: " << deserializedPtr->name << std::endl;
    std::cout << "Value: " << std::fixed << std::setprecision(5)
	      << deserializedPtr->value << std::endl;
    std::cout << std::endl;

    std::cout << "=== Modification Test ===" << std::endl;
    deserializedPtr->id = 84;
    std::cout << "Modified ID through deserialized pointer to: "
	      << deserializedPtr->id << std::endl;
    std::cout << "Original data ID is now: " << originalData.id << std::endl;
    if (originalData.id == 84) {
	std::cout << "✓ Modification successful - both refer to same object!"
		  << std::endl;
    }

    return 0;
}
