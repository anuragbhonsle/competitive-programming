#include <bits/stdc++.h>
using namespace std;

void printPascal(int n) {
    for (int line = 0; line < n; line++) {
        int value = 1;
        for (int i = 0; i <= line; i++) {
            cout << value << " ";
            value = value * (line - i) / (i + 1);
        }
        cout << "\n";
    }
}

int main() {
    int n = 5;
    cout << "Pascal's Triangle with " << n << " rows:\n";
    printPascal(n);
    return 0;
}
