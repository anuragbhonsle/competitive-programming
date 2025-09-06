#include <bits/stdc++.h>
using namespace std;

void generateSubsets(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(cur);
        return;
    }
    // Exclude
    generateSubsets(idx + 1, nums, cur, ans);
    // Include
    cur.push_back(nums[idx]);
    generateSubsets(idx + 1, nums, cur, ans);
    cur.pop_back();
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> cur;
    vector<vector<int>> ans;
    generateSubsets(0, nums, cur, ans);
    for (auto& subset : ans) {
        for (int x : subset) cout << x << " ";
        cout << "\n";
    }
}
