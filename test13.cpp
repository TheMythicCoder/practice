#include <iostream>
#include <unordered_map>

int main() {
	std::unordered_map<int, int> numMap;
	// Insert elements
	numMap[1] = 100;
	numMap[2] = 200;
	numMap[3] = 300;

	// Iterate and print
	for (const auto& pair : numMap) {
		std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
	}

	// Find an element
	int key = 2;
	if (numMap.find(key) != numMap.end()) {
		std::cout << "Found key " << key << ": " << numMap[key] << std::endl;
	} else {
		std::cout << "Key " << key << " not found." << std::endl;
	}

	return 0;
}
