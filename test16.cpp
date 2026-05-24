#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, int> ageMap;

	// Insert elements
	ageMap["Alice"] = 30;
	ageMap["Bob"] = 25;
	ageMap["Charlie"] = 35;

	// Access and print elements
	for (const auto& pair : ageMap) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	// Find an element
	auto it = ageMap.find("Bob");
	if (it != ageMap.end()) {
		std::cout << "Found Bob, age: " << it->second << std::endl;
	}

	// Erase an element
	ageMap.erase("Alice");

	std::cout << "After erasing Alice:" << std::endl;
	for (const auto& pair : ageMap) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	return 0;
}
