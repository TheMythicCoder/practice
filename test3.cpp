#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a vector of integers
    vector<int> numbers;
    
    // Add elements to the vector using push_back
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);
    
    // Display vector size
    cout << "Vector size: " << numbers.size() << endl;
    
    // Access elements using index operator
    cout << "First element: " << numbers[0] << endl;
    cout << "Last element: " << numbers[numbers.size() - 1] << endl;
    
    // Iterate through vector using for loop
    cout << "All elements: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Iterate using range-based for loop
    cout << "Range-based loop: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Insert element at specific position
    numbers.insert(numbers.begin() + 2, 25);
    cout << "After insert: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Remove element at specific position
    numbers.erase(numbers.begin() + 2);
    cout << "After erase: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Remove last element using pop_back
    numbers.pop_back();
    cout << "After pop_back: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Clear all elements
    numbers.clear();
    cout << "Vector size after clear: " << numbers.size() << endl;
    
    return 0;
}
