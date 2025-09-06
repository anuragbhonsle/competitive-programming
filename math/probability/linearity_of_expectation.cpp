#include <bits/stdc++.h>
using namespace std;

// Example: expected number of heads in n coin tosses
double expectedHeads(int n) {
    // Each toss has expectation 0.5 for heads
    return n * 0.5;
}

int main() {
    int n = 10;
    cout << "Expected heads in " << n << " tosses = " << expectedHeads(n) << "\n";
    return 0;
}
