#include <bits/stdc++.h>
using namespace std;

// Top-down (Memoization)
int fibMemo(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

// Bottom-up (Tabulation)
int fibTab(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int main() {
    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << "Fib Memo(10): " << fibMemo(n, dp) << "\n";
    cout << "Fib Tab(10): " << fibTab(n) << "\n";
}
