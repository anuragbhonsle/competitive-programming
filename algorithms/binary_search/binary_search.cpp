#include <bits/stdc++.h>
using namespace std;

// Standard Binary Search
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // not found
}

// Lower Bound (first index where arr[i] >= target)
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < target) low = mid + 1;
        else high = mid;
    }
    return low;
}

// Upper Bound (first index where arr[i] > target)
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= target) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    vector<int> arr = {1, 3, 3, 5, 7, 9, 11};
    int target = 3;
    cout << "Binary Search Index: " << binarySearch(arr, target) << "\n";
    cout << "Lower Bound Index: " << lowerBound(arr, target) << "\n";
    cout << "Upper Bound Index: " << upperBound(arr, target) << "\n";
    return 0;
}
