#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 29; // 11101 in binary

    // Check if kth bit is set (0-indexed from right)
    int k = 3;
    cout << "Is " << k << "th bit set? " << ((n >> k) & 1) << "\n";

    // Set kth bit
    int setBit = n | (1 << k);
    cout << "After setting bit " << k << ": " << setBit << "\n";

    // Unset kth bit
    int unsetBit = n & ~(1 << k);
    cout << "After unsetting bit " << k << ": " << unsetBit << "\n";

    // Toggle kth bit
    int toggled = n ^ (1 << k);
    cout << "After toggling bit " << k << ": " << toggled << "\n";

    // Count set bits
    cout << "Number of set bits: " << __builtin_popcount(n) << "\n";

    // Check if power of two
    cout << n << (n && !(n & (n-1)) ? " is " : " is not ") << "a power of two\n";

    return 0;
}
