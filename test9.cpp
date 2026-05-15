#include <bits/stdc++.h>
using namespace std;

int main() {
    srand((unsigned)time(NULL));
    int n = 10;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 20 + 1;
    }

    vector<int> dp(n, 1);
    int lis = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis = max(lis, dp[i]);
    }

    cout << "Random array:";
    for (int x : a) {
        cout << " " << x;
    }
    cout << "\nLongest increasing subsequence length: " << lis << "\n";

    return 0;
}
