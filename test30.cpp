#include <bits/stdc++.h>
using namespace std;

// 0/1 knapsack solver using dynamic programming
long long knapsack(const vector<int>& w, const vector<int>& v, int W) {
    int n = w.size();
    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int cap = W; cap >= w[i]; cap--) {
            dp[cap] = max(dp[cap], dp[cap - w[i]] + v[i]);
        }
    }
    return dp[W];
}

// Input format:
// n W
// w1 v1
// w2 v2
// ...
// wn vn
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W;
    if (!(cin >> n >> W)) {
        return 0;
    }

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    long long result = knapsack(weight, value, W);
    cout << result << "\n";

    return 0;
}
