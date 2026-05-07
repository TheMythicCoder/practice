#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void readNumbersRecursively(vector<int> &numbers, int index) {
    if (index < 0) {
        return;
    }
    cout << "Enter number " << index + 1 << ": ";
    cin >> numbers[index];
    readNumbersRecursively(numbers, index - 1);
}

void findSubsetSums(const vector<int> &numbers, int target, int index, 
                    vector<int> &current, vector<vector<int>> &solutions) {
    if (index == (int)numbers.size()) {
        int sum = 0;
        for (int value : current) {
            sum += value;
        }
        if (sum == target) {
            solutions.push_back(current);
        }
        return;
    }

    // Exclude the current number
    findSubsetSums(numbers, target, index + 1, current, solutions);

    // Include the current number
    current.push_back(numbers[index]);
    findSubsetSums(numbers, target, index + 1, current, solutions);
    current.pop_back();
}

bool isPalindromeRecursively(const string &text, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (text[left] != text[right]) {
        return false;
    }
    return isPalindromeRecursively(text, left + 1, right - 1);
}

int nestedRecursion(int value, int depth) {
    if (depth == 0) {
        return value;
    }
    return nestedRecursion(nestedRecursion(value + 1, depth - 1), depth - 1);
}

void printIndentationTree(int depth, int maxDepth) {
    if (depth > maxDepth) {
        return;
    }
    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }
    cout << "Recursion depth " << depth << "\n";
    printIndentationTree(depth + 1, maxDepth);
}

int main() {
    int count;
    cout << "Enter how many numbers to provide: ";
    cin >> count;

    if (count <= 0) {
        cout << "Number of values must be positive." << endl;
        return 0;
    }

    vector<int> numbers(count);
    readNumbersRecursively(numbers, count - 1);

    int target;
    cout << "Enter a target sum to search for: ";
    cin >> target;

    vector<vector<int>> solutions;
    vector<int> current;
    findSubsetSums(numbers, target, 0, current, solutions);

    cout << "\nSubsets that sum to " << target << ":" << endl;
    if (solutions.empty()) {
        cout << "  None found." << endl;
    } else {
        for (const auto &subset : solutions) {
            cout << "  { ";
            for (int value : subset) {
                cout << value << " ";
            }
            cout << "}\n";
        }
    }

    string text;
    cout << "\nEnter a string to check for palindrome: ";
    cin >> text;

    bool palindrome = isPalindromeRecursively(text, 0, (int)text.size() - 1);
    cout << "The string '" << text << "' is "
         << (palindrome ? "a palindrome." : "not a palindrome.") << endl;

    int depth;
    cout << "\nEnter recursion depth for nested evaluation: ";
    cin >> depth;

    if (depth < 0) {
        cout << "Depth must be non-negative." << endl;
    } else {
        int nestedResult = nestedRecursion(1, depth);
        cout << "Nested recursion result starting from 1 at depth "
             << depth << " is " << nestedResult << "." << endl;
    }

    int maxDepth;
    cout << "\nEnter maximum recursion tree depth to print: ";
    cin >> maxDepth;
    cout << "Recursion indentation tree:" << endl;
    printIndentationTree(0, maxDepth);

    return 0;
}
int maxDepth;
    cout << "\nEnter maximum recursion tree depth to print: ";
    cin >> maxDepth;
    cout << "Recursion indentation tree:" << endl;
    printIndentationTree(0, maxDepth);

    return 0;