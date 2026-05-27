#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
    
    vector<int> numbers;
    for (int i = 0; i < 10; i++) {
        numbers.push_back(rand() % 100 + 1);
    }
    
    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    sort(numbers.begin(), numbers.end());
    
    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    cout << "Sum: " << sum << endl;
    
    return 0;
}