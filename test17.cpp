#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Memoization for knapsack using map
int knapsack(int idx, int W, const vector<int>& wt, const vector<int>& val, map<pair<int, int>, int>& dp) {
	if (idx == 0 || W == 0) return 0;
	pair<int, int> key = {idx, W};
	if (dp.count(key)) return dp[key];
	if (wt[idx-1] > W) {
		return dp[key] = knapsack(idx-1, W, wt, val, dp);
	} else {
		int include = val[idx-1] + knapsack(idx-1, W-wt[idx-1], wt, val, dp);
		int exclude = knapsack(idx-1, W, wt, val, dp);
		return dp[key] = max(include, exclude);
	}
}

int main() {
	int n, W;
	cout << "Enter number of items: ";
	cin >> n;
	vector<int> wt(n), val(n);
	cout << "Enter weights: ";
	for (int i = 0; i < n; ++i) cin >> wt[i];
	cout << "Enter values: ";
	for (int i = 0; i < n; ++i) cin >> val[i];
	cout << "Enter knapsack capacity: ";
	cin >> W;
	map<pair<int, int>, int> dp;
	int maxVal = knapsack(n, W, wt, val, dp);
	cout << "Maximum value in knapsack: " << maxVal << endl;
	return 0;
}
