#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void findSubsequences(std::string& str) {
    int n = str.size();
    for (int i = 0; i < (1 << n); ++i) {
        std::bitset<32> b(i);
        std::cout << "Subsequence: ";
        for (int j = 0; j < n; ++j) {
            if (b[j]) {
                std::cout << str[j] << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::string str = "abc";
    findSubsequences(str);
    return 0;
}
