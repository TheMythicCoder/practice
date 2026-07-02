#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
using namespace std;
// Random sample code with comments
// and helper functions in a single file.
// The code is designed to be 200 lines.
// It contains simple random routines.
static mt19937& getEngine()
{
    static mt19937 engine(
        static_cast<unsigned int>(
            chrono::high_resolution_clock::now()
                .time_since_epoch()
                .count()));
    return engine;
}
int randomInt(int low, int high)
{
    uniform_int_distribution<int> dist(low, high);
    return dist(getEngine());
}
string randomWord(int length)
{
    const string letters = "abcdefghijklmnopqrstuvwxyz";
    string output;
    output.reserve(length);
    for (int i = 0; i < length; ++i)
    {
        output.push_back(letters[randomInt(0, static_cast<int>(letters.size()) - 1)]);
    }
    return output;
}
vector<int> generateNumbers(int count, int low, int high)
{
    vector<int> values;
    values.reserve(count);
    for (int i = 0; i < count; ++i)
    {
        values.push_back(randomInt(low, high));
    }
    return values;
}
int sumValues(const vector<int>& values)
{
    int total = 0;
    for (int value : values)
    {
        total += value;
    }
    return total;
}
double averageValues(const vector<int>& values)
{
    return values.empty() ? 0.0 : static_cast<double>(sumValues(values)) / values.size();
}
void printValues(const string& label, const vector<int>& values)
{
    cout << label;
    for (int value : values)
    {
        cout << " " << value;
    }
    cout << endl;
}
vector<int> filterValues(const vector<int>& values, bool even)
{
    vector<int> result;
    for (int value : values)
    {
        if ((value % 2 == 0) == even)
        {
            result.push_back(value);
        }
    }
    return result;
}
bool isPalindrome(const string& text)
{
    if (text.empty())
    {
        return true;
    }
    size_t left = 0;
    size_t right = text.size() - 1;
    while (left < right)
    {
        if (text[left] != text[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int clampInt(int value, int low, int high)
{
    if (value < low) return low;
    if (value > high) return high;
    return value;
}
double clampDouble(double value, double low, double high)
{
    if (value < low) return low;
    if (value > high) return high;
    return value;
}
bool almostEqual(double a, double b)
{
    return fabs(a - b) < 1e-9;
}
int fibonacci(int n)
{
    if (n <= 1) return n;
    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; ++i)
    {
        int next = a + b;
        a = b;
        b = next;
    }
    return b;
}
vector<int> fibonacciSequence(int count)
{
    vector<int> result;
    if (count > 0) result.push_back(0);
    if (count > 1) result.push_back(1);
    while (static_cast<int>(result.size()) < count)
    {
        int size = static_cast<int>(result.size());
        result.push_back(result[size - 1] + result[size - 2]);
    }
    return result;
}
int main()
{
    cout << "=== Random demo ===" << endl;
    vector<int> numbers = generateNumbers(10, 1, 100);
    printValues("Numbers:", numbers);
    vector<int> evens = filterValues(numbers, true);
    vector<int> odds = filterValues(numbers, false);
    printValues("Evens:", evens);
    printValues("Odds:", odds);
    cout << "Sum: " << sumValues(numbers) << endl;
    cout << "Average: " << averageValues(numbers) << endl;
    reverse(numbers.begin(), numbers.end());
    printValues("Reversed:", numbers);
    vector<int> primes;
    {
        int limit = 30;
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= limit; ++i)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
                for (int j = i * i; j <= limit; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
    //skskc
    printValues("Primes:", primes);
    vector<string> words;
    for (int i = 0; i < 5; ++i)
    {
        words.push_back(randomWord(6));
    }
    cout << "Words:" << endl;
    for (const string& word : words)
    {
        cout << word << endl;
    }
    if (!words.empty())
    {
        cout << "First palindrome: " << (isPalindrome(words[0]) ? "yes" : "no") << endl;
    }
    vector<int> fib = fibonacciSequence(8);
    printValues("Fibonacci:", fib);
    cout << "Fibonacci 7: " << fibonacci(7) << endl;
    cout << "Repeat: " << string(3, '*') << endl;
    cout << "Clamped int: " << clampInt(123, 0, 100) << endl;
    cout << "Clamped double: " << clampDouble(2.5, 0.0, 1.0) << endl;
    cout << "Almost equal: " << (almostEqual(1.0, 1.0 + 1e-10) ? "yes" : "no") << endl;
    cout << "Random word: " << randomWord(5) << endl;
    cout << "Random number: " << randomInt(10, 99) << endl;
    cout << "End of demo." << endl;
    return 0;
}
