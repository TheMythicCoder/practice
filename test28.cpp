#include <bits/stdc++.h>
using namespace std;

// Random C++ code (~40 lines) demonstrating small utilities

int square(int x) {
	return x * x;
}

string reverseWords(const string &s) {
	stringstream ss(s);
	string word, out;
	bool first = true;
	while (ss >> word) {
		if (!first) out = word + " " + out;
		else { out = word; first = false; }
	}
	return out;
}

vector<int> uniqueSorted(const vector<int>& v) {
	set<int> s(v.begin(), v.end());
	return vector<int>(s.begin(), s.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << "Random C++ Utilities" << '\n';
	cout << "square(7) = " << square(7) << '\n';

	string sample = "this is a sample line";
	cout << "Reversed words: '" << reverseWords(sample) << "'" << '\n';

	vector<int> v = {5,2,3,5,2,9,1};
	auto u = uniqueSorted(v);
	cout << "Unique sorted:";
	for (int x : u) cout << ' ' << x;
	cout << '\n';

	return 0;
}
