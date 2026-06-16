#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate factorial
int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    return n * factorial(n - 1);
}

// Function to check if a number is prime
bool isPrime(int num) {
    // Numbers less than 2 are not prime
    if (num < 2) {
        return false;
    }
    // Check for divisibility from 2 to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    // If no divisors found, number is prime
    return true;
}

// Function to find the maximum element in a vector
int findMax(const vector<int>& arr) {
    // Initialize max with first element
    int max_val = arr[0];
    // Iterate through array to find maximum
    for (int val : arr) {
        if (val > max_val) {
            max_val = val;
        }
    }
    // Return the maximum value found
    return max_val;
}

// Function to calculate sum of all elements
int calculateSum(const vector<int>& arr) {
    // Initialize sum to zero
    int sum = 0;
    // Add each element to sum
    for (int val : arr) {
        sum += val;
    }
    // Return total sum
    return sum;
}

// Function to reverse a vector
void reverseVector(vector<int>& arr) {
    // Use algorithm library's reverse function
    reverse(arr.begin(), arr.end());
}

// Function to print vector elements
void printVector(const vector<int>& arr) {
    // Iterate through each element
    for (int val : arr) {
        // Print element followed by space
        cout << val << " ";
    }
    // Print newline after all elements
    cout << endl;
}

// Function to sort vector in ascending order
void sortVector(vector<int>& arr) {
    // Use algorithm library's sort function
    sort(arr.begin(), arr.end());
}

// Function to count occurrences of a value
int countOccurrences(const vector<int>& arr, int target) {
    // Initialize count to zero
    int count = 0;
    // Iterate through array checking for target
    for (int val : arr) {
        if (val == target) {
            // Increment count when target found
            count++;
        }
    }
    // Return total occurrences
    return count;
}

// Main function - entry point of program
int main() {
    // Create a vector with initial values
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // Display original vector
    cout << "Original vector: ";
    printVector(numbers);
    
    // Sort the vector
    sortVector(numbers);
    cout << "Sorted vector: ";
    printVector(numbers);
    
    // Find and display maximum element
    int max_elem = findMax(numbers);
    cout << "Maximum element: " << max_elem << endl;
    
    // Calculate and display sum
    int total = calculateSum(numbers);
    cout << "Sum of elements: " << total << endl;
    
    // Check if 5 is prime and display result
    cout << "Is 5 prime? " << (isPrime(5) ? "Yes" : "No") << endl;
    
    // Calculate factorial of 5
    cout << "Factorial of 5: " << factorial(5) << endl;
    
    // Return success status
    return 0;
}
