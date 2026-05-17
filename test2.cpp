#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

struct Item {
    int weight;
    int value;
    double ratio() const {
        return static_cast<double>(value) / weight;
    }
};

int main() {
    std::vector<Item> items = {
        {4, 10}, {3, 4}, {2, 7}, {5, 12}, {1, 2}, {6, 13}, {4, 8}
    };
    int capacity = 15;

    std::mt19937 rng(
        static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));

    int bestValue = 0;
    std::vector<int> bestSolution(items.size(), 0);

    for (int iter = 0; iter < 1000; ++iter) {
        std::vector<int> order(items.size());
        for (size_t i = 0; i < items.size(); ++i)
            order[i] = static_cast<int>(i);

        std::shuffle(order.begin(), order.end(), rng);

        int currentWeight = 0;
        int currentValue = 0;
        std::vector<int> solution(items.size(), 0);

        for (int index : order) {
            if (currentWeight + items[index].weight <= capacity) {
                solution[index] = 1;
                currentWeight += items[index].weight;
                currentValue += items[index].value;
            }
        }

        if (currentValue > bestValue) {
            bestValue = currentValue;
            bestSolution = solution;
        }
    }

    std::cout << "Random greedy knapsack best value: " << bestValue << "\n";
    std::cout << "Selected items (weight,value):\n";
    for (size_t i = 0; i < items.size(); ++i) {
        if (bestSolution[i]) {
            std::cout << "  (" << items[i].weight << ", " << items[i].value << ")\n";
        }
    }

    return 0;
}
