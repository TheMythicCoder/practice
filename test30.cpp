#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map with string keys and int values
    std::unordered_map<std::string, int> fruitCount;
    
    // Insert elements
    fruitCount["apple"] = 5;
    fruitCount["banana"] = 3;
    fruitCount["orange"] = 7;
    fruitCount["mango"] = 2;
    fruitCount["grape"] = 10;
    
    // Display all elements
    std::cout << "Fruit Inventory:\n";
    for (const auto& pair : fruitCount) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    
    // Check if a key exists
    if (fruitCount.find("apple") != fruitCount.end()) {
        std::cout << "\nApples found: " << fruitCount["apple"] << "\n";
    }
    
    // Update a value
    fruitCount["banana"] += 2;
    std::cout << "Updated banana count: " << fruitCount["banana"] << "\n";
    
    // Erase an element
    fruitCount.erase("grape");
    std::cout << "\nAfter removing grapes:\n";
    
    // Display remaining elements
    for (const auto& pair : fruitCount) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    
    // Get size
    std::cout << "\nTotal unique fruits: " << fruitCount.size() << "\n";
    
    return 0;
}
