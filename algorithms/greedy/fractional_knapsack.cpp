#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    double res = 0.0;
    for (auto& it : items) {
        if (W >= it.weight) {
            W -= it.weight;
            res += it.value;
        } else {
            res += it.value * ((double)W / it.weight);
            break;
        }
    }
    return res;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    cout << "Max Value in Knapsack: " << fractionalKnapsack(W, items) << "\n";
}
