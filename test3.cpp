#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(const vector<int>& v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	vector<int> numbers;
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	cout << "Enter " << n << " numbers:\n";
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		numbers.push_back(x);
	}
	sort(numbers.begin(), numbers.end());
	cout << "Sorted numbers: ";
	printVector(numbers);
	return 0;
}
