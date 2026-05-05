#include <iostream>

int main() {
    int n;
    if (!(std::cin >> n)) {
        return 0;
    }
    long long sum = static_cast<long long>(n) * (n + 1) / 2;
    std::cout << sum << std::endl;
    return 0;
}

