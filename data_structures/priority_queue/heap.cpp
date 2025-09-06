#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(10); maxHeap.push(5); maxHeap.push(20);
    minHeap.push(10); minHeap.push(5); minHeap.push(20);

    cout << "Max heap top: " << maxHeap.top() << "\n"; maxHeap.pop();
    cout << "Min heap top: " << minHeap.top() << "\n"; minHeap.pop();
}
