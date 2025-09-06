#include <bits/stdc++.h>
using namespace std;

// Select max number of non-overlapping activities
int activitySelection(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++)
        activities.push_back({finish[i], start[i]});

    sort(activities.begin(), activities.end());
    int count = 1, lastFinish = activities[0].first;

    for (int i = 1; i < n; i++) {
        if (activities[i].second >= lastFinish) {
            count++;
            lastFinish = activities[i].first;
        }
    }
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << "Max Activities: " << activitySelection(start, finish) << "\n";
}
