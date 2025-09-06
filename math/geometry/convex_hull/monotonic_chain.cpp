#include <bits/stdc++.h>
using namespace std;

struct P { long long x, y; };
bool cmpPoint(const P &a, const P &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
long long cross(const P &o, const P &a, const P &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// monotonic chain / Andrew's algorithm -> O(n log n)
vector<P> convexHull(vector<P> pts) {
    int n = pts.size();
    if (n <= 1) return pts;
    sort(pts.begin(), pts.end(), cmpPoint);
    vector<P> lower, upper;
    for (int i = 0; i < n; i++) {
        while (lower.size() >= 2 && cross(lower[lower.size()-2], lower.back(), pts[i]) <= 0)
            lower.pop_back();
        lower.push_back(pts[i]);
    }
    for (int i = n-1; i >= 0; i--) {
        while (upper.size() >= 2 && cross(upper[upper.size()-2], upper.back(), pts[i]) <= 0)
            upper.pop_back();
        upper.push_back(pts[i]);
    }
    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower; // points in CCW order
}

int main() {
    vector<P> pts = {{0,0},{1,1},{2,2},{0,2},{2,0},{1,2},{3,1}};
    auto hull = convexHull(pts);
    cout << "Hull size: " << hull.size() << "\n";
    for (auto &p : hull) cout << p.x << " " << p.y << "\n";
}
