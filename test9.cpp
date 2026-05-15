#include <bits/stdc++.h>
using namespace std;

int roll(int a, int b) {
    return a + rand() % (b - a + 1);
}

string random_word(int len) {
    static const char* src = "abcdefghijklmnopqrstuvwxyz";
    string s; s.reserve(len);
    for (int i = 0; i < len; ++i) s.push_back(src[rand() % 26]);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned)time(nullptr));

    for (int i = 0; i < 30; ++i) {
        int a = roll(1, 100);
        int b = roll(101, 1000);
        string w = random_word(1 + rand() % 8);
        cout << i << ": " << w << " " << a << "," << b << "\n";
    }

    return 0;
}
