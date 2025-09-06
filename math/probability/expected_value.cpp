#include <bits/stdc++.h>
using namespace std;

// Expected value = sum of (value * probability)
double expectedValue(vector<int> values, vector<double> probs) {
    double result = 0;
    for (int i = 0; i < values.size(); i++) {
        result += values[i] * probs[i];
    }
    return result;
}

int main() {
    // Example: dice roll {1,2,3,4,5,6} with equal probability
    vector<int> values = {1, 2, 3, 4, 5, 6};
    vector<double> probs(6, 1.0 / 6.0);

    cout << "Expected dice roll = " << expectedValue(values, probs) << "\n";
    return 0;
}
