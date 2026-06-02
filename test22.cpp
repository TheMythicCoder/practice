// Matrix using vector of vectors in C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int rows, cols;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;

	vector<vector<int>> matrix(rows, vector<int>(cols));

	cout << "Enter matrix elements:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << "Matrix is:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
