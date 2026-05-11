#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    std::vector<int> v;
    for(int i = 0; i < 10; i++) v.push_back(dis(gen));
    std::sort(v.begin(), v.end(), std::greater<int>());
    for(int i : v) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}