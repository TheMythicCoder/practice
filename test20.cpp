#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
    vector<int> numbers;
    
    // Generate random numbers
    for (int i = 0; i < 10; i++) {
        numbers.push_back(rand() % 100);
    }
    
    // Print original numbers
    cout << "Original numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Sort the numbers
    sort(numbers.begin(), numbers.end());
    
    // Print sorted numbers
    cout << "Sorted numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}