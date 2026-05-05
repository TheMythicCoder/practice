#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    long long sum = n * (n + 1) / 2;
    std::cout << sum;
    return 0;
}
