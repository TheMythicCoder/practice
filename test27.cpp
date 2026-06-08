#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    srand(time(0));
    
    vector<int> numbers;
    
    for (int i = 0; i < 10; i++) {
        numbers.push_back(rand() % 100);
    }
    
    cout << "Random numbers generated:\n";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n";
    
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    
    cout << "Sum: " << sum << "\n";
    cout << "Average: " << (sum / 10.0) << "\n";
    
    return 0;
}
