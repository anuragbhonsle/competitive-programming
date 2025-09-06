#include <bits/stdc++.h>
using namespace std;

void generatePermutations(vector<int>& nums, int l, int r, vector<vector<int>>& ans) {
    if (l == r) {
        ans.push_back(nums);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(nums[l], nums[i]);
        generatePermutations(nums, l + 1, r, ans);
        swap(nums[l], nums[i]); // backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    generatePermutations(nums, 0, nums.size() - 1, ans);
    for (auto& perm : ans) {
        for (int x : perm) cout << x << " ";
        cout << "\n";
    }
}
