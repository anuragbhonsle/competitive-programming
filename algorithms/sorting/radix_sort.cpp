#include <bits/stdc++.h>
using namespace std;

void countingSortExp(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n), count(10, 0);

    for (int x : arr) count[(x / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxEl = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxEl / exp > 0; exp *= 10)
        countingSortExp(arr, exp);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}
