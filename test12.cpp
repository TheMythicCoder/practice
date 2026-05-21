#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v) {
	cout << "Vector elements: ";
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	vector<int> numbers;
	for (int i = 1; i <= 5; ++i) {
		numbers.push_back(i * 2);
	}
	printVector(numbers);
	int sum = 0;
	for (int num : numbers) {
		sum += num;
	}
	cout << "Sum: " << sum << endl;
	return 0;
}
