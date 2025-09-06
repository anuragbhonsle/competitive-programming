#include <bits/stdc++.h>
using namespace std;

// Minimum number of coins to make target
int coinChange(vector<int>& coins, int target) {
    const int INF = 1e9;
    vector<int> dp(target + 1, INF);
    dp[0] = 0;
    for (int c : coins) {
        for (int i = c; i <= target; i++) {
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    return dp[target] == INF ? -1 : dp[target];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int target = 11;
    cout << "Min coins: " << coinChange(coins, target) << "\n";
}
