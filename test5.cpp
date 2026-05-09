#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T))
        return 0;

    for (int tc = 1; tc <= T; ++tc) {
        int n, cap;
        cin >> n >> cap;

        vector<int> w(n), v(n);
        for (int i = 0; i < n; ++i)
            cin >> w[i];
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        int m;
        cin >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; ++i)
            cin >> arr[i];

        string s;
        cin >> s;

        int R, C;
        cin >> R >> C;
        vector<vector<int>> grid(R, vector<int>(C));
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                cin >> grid[i][j];

        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; ++i)
            cin >> queries[i];

        vector<ll> knapsackDp(cap + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int weight = cap; weight >= w[i]; --weight) {
                knapsackDp[weight] = max(knapsackDp[weight], knapsackDp[weight - w[i]] + v[i]);
            }
        }
        ll knapsackValue = 0;
        for (int weight = 0; weight <= cap; ++weight)
            knapsackValue = max(knapsackValue, knapsackDp[weight]);

        int lis = 0;
        vector<int> tails;
        for (int x : arr) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
            lis = max(lis, (int)tails.size());
        }

        int nstr = s.size();
        vector<vector<int>> pal(nstr + 1, vector<int>(nstr + 1, 0));
        for (int i = nstr - 1; i >= 0; --i) {
            pal[i][i] = 1;
            for (int j = i + 1; j < nstr; ++j) {
                if (s[i] == s[j])
                    pal[i][j] = pal[i + 1][j - 1] + 2;
                else
                    pal[i][j] = max(pal[i + 1][j], pal[i][j - 1]);
            }
        }
        int longestPalindromicSubsequence = nstr ? pal[0][nstr - 1] : 0;

        vector<vector<ll>> sum(R, vector<ll>(C, LLONG_MIN));
        vector<vector<ll>> ways(R, vector<ll>(C, 0));
        if (R > 0 && C > 0) {
            sum[0][0] = grid[0][0];
            ways[0][0] = 1;
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    if (i == 0 && j == 0)
                        continue;
                    ll best = LLONG_MIN;
                    ll count = 0;
                    if (i > 0 && sum[i - 1][j] > LLONG_MIN / 2) {
                        ll cand = sum[i - 1][j] + grid[i][j];
                        if (cand > best) {
                            best = cand;
                            count = ways[i - 1][j];
                        } else if (cand == best) {
                            count += ways[i - 1][j];
                        }
                    }
                    if (j > 0 && sum[i][j - 1] > LLONG_MIN / 2) {
                        ll cand = sum[i][j - 1] + grid[i][j];
                        if (cand > best) {
                            best = cand;
                            count = ways[i][j - 1];
                        } else if (cand == best) {
                            count += ways[i][j - 1];
                        }
                    }
                    sum[i][j] = best;
                    ways[i][j] = count;
                }
            }
        }
        ll maxGridPathSum = (R > 0 && C > 0) ? sum[R - 1][C - 1] : 0;
        ll maxGridPathCount = (R > 0 && C > 0) ? ways[R - 1][C - 1] : 0;

        int maxQuery = 0;
        if (q > 0)
            maxQuery = *max_element(queries.begin(), queries.end());

        vector<ll> subsetWays(maxQuery + 1, 0);
        subsetWays[0] = 1;
        for (int x : arr) {
            for (int j = maxQuery; j >= x; --j) {
                subsetWays[j] += subsetWays[j - x];
            }
        }

        cout << "Case #" << tc << ":\n";
        cout << "  knapsack_max_value=" << knapsackValue << "\n";
        cout << "  longest_increasing_subsequence=" << lis << "\n";
        cout << "  longest_palindromic_subsequence=" << longestPalindromicSubsequence << "\n";
        cout << "  max_grid_path_sum=" << maxGridPathSum << " path_count=" << maxGridPathCount << "\n";
        for (int i = 0; i < q; ++i) {
            ll waysForQuery = (queries[i] <= maxQuery ? subsetWays[queries[i]] : 0);
            cout << "  subset_sum_ways(" << queries[i] << ")=" << waysForQuery << "\n";
        }
    }

    return 0;
}
