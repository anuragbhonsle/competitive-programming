#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 29; // 11101 in binary
    int k = 3;

    // Check if kth bit is set (0-indexed from right)
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

    // ---- EXTRA TRICKS ----

    // 1. Turn off the rightmost set bit
    cout << "n with rightmost set bit turned off: " << (n & (n-1)) << "\n";

    // 2. Extract the rightmost set bit
    cout << "Rightmost set bit of n: " << (n & -n) << "\n";

    // 3. Swap two numbers without temp variable
    int a = 5, b = 7;
    a ^= b; b ^= a; a ^= b;
    cout << "Swapped a= " << a << ", b= " << b << "\n";

    // 4. Check if kth bit from left (MSB side) is set
    int totalBits = 32;
    int msbK = 28; // check 28th bit from left
    cout << "Is " << msbK << "th bit from left set? "
         << ((n >> (totalBits - msbK - 1)) & 1) << "\n";

    // 5. Reverse all bits of n
    unsigned int x = n;
    x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
    x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
    x = ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4);
    x = ((x >> 8) & 0x00FF00FF) | ((x & 0x00FF00FF) << 8);
    x = (x >> 16) | (x << 16);
    cout << "Reversed bits: " << x << "\n";

    // 6. Find log2(n) (position of highest set bit)
    cout << "Highest set bit index: " << (31 - __builtin_clz(n)) << "\n";

    // 7. Round up to next power of two
    unsigned int p = n;
    p--;
    p |= p >> 1;
    p |= p >> 2;
    p |= p >> 4;
    p |= p >> 8;
    p |= p >> 16;
    p++;
    cout << "Next power of two >= n: " << p << "\n";

    // 8. Gray code of n (binary reflected)
    int gray = n ^ (n >> 1);
    cout << "Gray code of n: " << gray << "\n";

    return 0;
}

