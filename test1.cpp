// Simple 15-line C++ program
#include <iostream>
using namespace std;

int add(int a, int b) {
	return a + b;
}

int main() {
	int x, y;
	cout << "Enter two numbers: ";
	cin >> x >> y;
	int sum = add(x, y);
	cout << "Sum is: " << sum << endl;
	if (sum % 2 == 0) {
		cout << "The sum is even." << endl;
	} else {
		cout << "The sum is odd." << endl;
	}
	return 0;
}
