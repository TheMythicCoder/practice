#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int numbers[10];
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 100 + 1;
    }
    
    cout << "Random numbers: ";
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    return 0;
}