#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    const int n = 10;
    const int capacity = 50;

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> weightDist(1, 15);
    std::uniform_int_distribution<int> valueDist(1, 30);

    std::vector<int> weights(n);
    std::vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        weights[i] = weightDist(rng);
        values[i] = valueDist(rng);
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (w >= weights[i - 1]) {
                dp[i][w] = std::max(dp[i][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    std::cout << "Random 0/1 Knapsack\n";
    std::cout << "Capacity: " << capacity << "\n";
    std::cout << "Items:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "  Item " << i + 1 << ": weight=" << weights[i] << ", value=" << values[i] << "\n";
    }
    std::cout << "Maximum value: " << dp[n][capacity] << "\n";

    int w = capacity;
    std::vector<int> selected;
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i);
            w -= weights[i - 1];
        }
    }

    std::cout << "Selected items:";
    for (int idx = selected.size() - 1; idx < selected.size(); --idx) {
        std::cout << " " << selected[idx];
        if (idx == 0) break;
    }
    std::cout << "\n";

    return 0;
}
