#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    std::vector<int> values(10);
    std::iota(values.begin(), values.end(), 1);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(values.begin(), values.end(), gen);

    std::cout << "Random values:";
    for (int v : values) {
        std::cout << ' ' << v;
    }
    std::cout << '\n';

    return 0;
}
