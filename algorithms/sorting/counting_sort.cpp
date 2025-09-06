#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxEl = *max_element(arr.begin(), arr.end());
    vector<int> count(maxEl + 1, 0);

    for (int x : arr) count[x]++;
    int idx = 0;
    for (int i = 0; i <= maxEl; i++) {
        while (count[i]--) arr[idx++] = i;
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}
