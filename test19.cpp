#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
long long dp[MAXN][2];

// Tree DP Example: Maximum weight independent set
void dfs(int u, int parent) {
    dp[u][0] = 0;  // dp[u][0] = max sum when u is NOT selected
    dp[u][1] = 0;  // dp[u][1] = max sum when u IS selected
    
    for (int v : adj[u]) {
        if (v == parent) continue;
        
        dfs(v, u);
        
        // If u is not selected, we can select or not select child v
        dp[u][0] += max(dp[v][0], dp[v][1]);
        
        // If u is selected, child v cannot be selected
        dp[u][1] += dp[v][0];
    }
    
    // If u is selected, add its weight (assumed 1 here)
    dp[u][1] += 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, -1);
    
    cout << max(dp[1][0], dp[1][1]) << "\n";
    
    return 0;
}
