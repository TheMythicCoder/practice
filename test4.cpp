
#include <bits/stdc++.h>
using namespace std;

// Backtracking + DP (memoization) example:
// Count number of subsets that sum to a given target.

long long dfs(int i, int sum, const vector<int>& a, int target, vector<unordered_map<int,long long>>& memo) {
	if (sum == target) return 1;
	if (i == (int)a.size()) return 0;
	if (sum > target) return 0; // assuming non-negative numbers
	auto it = memo[i].find(sum);
	if (it != memo[i].end()) return it->second;

	// choice: skip current
	long long ways = dfs(i+1, sum, a, target, memo);
	// choice: take current
	ways += dfs(i+1, sum + a[i], a, target, memo);

	memo[i][sum] = ways;
	return ways;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; long long target;
	if (!(cin >> n >> target)) {
		// Example: if no input, run demo
		vector<int> a = {2,3,5,6,8,10};
		target = 10; n = a.size();
		vector<unordered_map<int,long long>> memo(n);
		cout << dfs(0, 0, a, target, memo) << '\n';
		return 0;
	}

	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	// This memoization assumes sums are non-negative and not too large.
	vector<unordered_map<int,long long>> memo(n);
	cout << dfs(0, 0, a, (int)target, memo) << '\n';
	return 0;
}

