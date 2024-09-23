#include <bits/stdc++.h>
using namespace std;

typedef long long u64;

bool isPalindromeInBase(u64 N, int base) {
    vector<u64> digits;
    u64 temp = N;

    while (temp > 0) {
        digits.push_back(temp % base);
        temp /= base;
    }

    int start = 0;
    int end = digits.size() - 1;
    while (start < end) {
        if (digits[start] != digits[end]) {
            return false;
        }
        ++start;
        --end;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    u64 N;
    cin >> N;

    vector<u64> palindromic_bases;
    bool found_palindrome = false;

    for (int base = 2; base <= sqrt(N); ++base) {
        if (isPalindromeInBase(N, base)) {
            palindromic_bases.push_back(base);
            found_palindrome = true;
        }
    }

    for (u64 q = 1; q * q <= N; ++q) {
        u64 base = (N - q) / q;
        if (base > sqrt(N) && base >= 2 && N % base == q) {
            palindromic_bases.push_back(base);
            found_palindrome = true;
        }
    }

    if (!found_palindrome) {
        cout << "*" << endl;
    } else {
        sort(palindromic_bases.begin(), palindromic_bases.end());
        for (u64 base : palindromic_bases) {
            cout << base << " ";
        }
        cout << endl;
    }

    return 0;
}
