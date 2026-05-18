#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    std::cout << "Sorted array: ";
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
