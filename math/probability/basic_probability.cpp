#include <bits/stdc++.h>
using namespace std;

// Probability = favorable / total
double probability(int favorable, int total) {
    if (total == 0) return 0;
    return (double)favorable / total;
}

int main() {
    int favorable = 2; // rolling a 1 or 2
    int total = 6;     // dice faces
    cout << "P(rolling 1 or 2) = " << probability(favorable, total) << "\n";
    return 0;
}
