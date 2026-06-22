#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s1 = "Hello";
	string s2 = "World";
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;

	// Concatenation
	string s3 = s1 + " " + s2;
	cout << "Concatenated: " << s3 << endl;

	// Length
	cout << "Length of s3: " << s3.length() << endl;

	// Substring
	string sub = s3.substr(0, 5);
	cout << "Substring: " << sub << endl;

	// Find
	size_t pos = s3.find("World");
	if (pos != string::npos)
		cout << "'World' found at: " << pos << endl;

	// Replace
	s3.replace(6, 5, "C++");
	cout << "After replace: " << s3 << endl;

	// Insert
	s3.insert(6, "amazing ");
	cout << "After insert: " << s3 << endl;

	// Erase
	s3.erase(6, 8);
	cout << "After erase: " << s3 << endl;

	// Reverse
	reverse(s3.begin(), s3.end());
	cout << "Reversed: " << s3 << endl;

	// Iterate
	cout << "Characters: ";
	for (char c : s3) cout << c << ' ';
	cout << endl;

	return 0;
}
