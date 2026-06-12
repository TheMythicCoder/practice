#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int sumVector(const vector<int>& values) {
    return accumulate(values.begin(), values.end(), 0);
}

vector<int> generateSequence(int size) {
    vector<int> sequence;
    sequence.reserve(size);
    for (int i = 1; i <= size; ++i) {
        sequence.push_back(i * 2);
    }
    return sequence;
}

void printValues(const vector<int>& values, const string& label) {
    cout << label << ": ";
    for (size_t i = 0; i < values.size(); ++i) {
        cout << values[i];
        if (i + 1 < values.size()) {
            cout << ", ";
        }
    }
    cout << "\n";
}

int main() {
    const int count = 10;
    vector<int> values = generateSequence(count);
    printValues(values, "Sequence");

    int total = sumVector(values);
    cout << "Sum of values: " << total << "\n";

    int threshold = 10;
    vector<int> filtered;
    copy_if(values.begin(), values.end(), back_inserter(filtered),
            [threshold](int x) { return x > threshold; });

    printValues(filtered, "Filtered values");
    cout << "Count of filtered values: " << filtered.size() << "\n";

    return 0;
}
