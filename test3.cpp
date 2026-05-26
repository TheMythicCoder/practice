// Example: Comprehensive usage of std::vector in C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

void print_vector(const std::vector<int>& v, const std::string& label = "Vector") {
	std::cout << label << ": ";
	for (int x : v) std::cout << x << ' ';
	std::cout << '\n';
}

int main() {
	// 1. Create a vector and initialize
	std::vector<int> v1 = {1, 2, 3, 4, 5};
	print_vector(v1, "Initial v1");

	// 2. Add elements
	v1.push_back(6);
	v1.push_back(7);
	print_vector(v1, "After push_back");

	// 3. Remove last element
	v1.pop_back();
	print_vector(v1, "After pop_back");

	// 4. Insert at position
	v1.insert(v1.begin() + 2, 99);
	print_vector(v1, "After insert at pos 2");

	// 5. Erase element at position
	v1.erase(v1.begin() + 2);
	print_vector(v1, "After erase at pos 2");

	// 6. Resize vector
	v1.resize(10, 42);
	print_vector(v1, "After resize to 10 with 42");

	// 7. Access elements
	std::cout << "Element at 0: " << v1[0] << '\n';
	std::cout << "Element at 3: " << v1.at(3) << '\n';

	// 8. Iterate using iterator
	std::cout << "Iterate using iterator: ";
	for (auto it = v1.begin(); it != v1.end(); ++it) std::cout << *it << ' ';
	std::cout << '\n';

	// 9. Sort vector
	std::sort(v1.begin(), v1.end());
	print_vector(v1, "After sort");

	// 10. Reverse vector
	std::reverse(v1.begin(), v1.end());
	print_vector(v1, "After reverse");

	// 11. Find element
	auto it = std::find(v1.begin(), v1.end(), 42);
	if (it != v1.end())
		std::cout << "Found 42 at position: " << std::distance(v1.begin(), it) << '\n';
	else
		std::cout << "42 not found\n";

	// 12. Sum all elements
	int sum = std::accumulate(v1.begin(), v1.end(), 0);
	std::cout << "Sum of elements: " << sum << '\n';

	// 13. Copy vector
	std::vector<int> v2 = v1;
	print_vector(v2, "Copied v2");

	// 14. Move vector
	std::vector<int> v3 = std::move(v2);
	print_vector(v3, "Moved v3");
	print_vector(v2, "After move v2");

	// 15. Clear vector
	v3.clear();
	print_vector(v3, "After clear v3");

	// 16. Capacity and size
	std::cout << "v1 size: " << v1.size() << ", capacity: " << v1.capacity() << '\n';

	// 17. Emplace_back
	v1.emplace_back(100);
	print_vector(v1, "After emplace_back 100");

	// 18. Using vector of vectors
	std::vector<std::vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
	std::cout << "Matrix:\n";
	for (const auto& row : matrix) {
		for (int x : row) std::cout << x << ' ';
		std::cout << '\n';
	}

	// 19. Using std::fill
	std::fill(v1.begin(), v1.end(), 7);
	print_vector(v1, "After fill with 7");

	// 20. Remove all 7s
	v1.erase(std::remove(v1.begin(), v1.end(), 7), v1.end());
	print_vector(v1, "After removing all 7s");

	return 0;
}
