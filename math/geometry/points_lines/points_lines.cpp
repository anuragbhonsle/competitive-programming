#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(const Point &a, const Point &b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// orientation: 0 -> collinear, 1 -> clockwise, 2 -> counterclockwise
int orientation(const Point &a, const Point &b, const Point &c) {
    double val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (fabs(val) < 1e-12) return 0;
    return (val > 0) ? 1 : 2;
}

// check if two segments p1q1 and p2q2 intersect
bool onSegment(const Point &p, const Point &q, const Point &r) {
    return min(p.x, r.x) <= q.x + 1e-12 && q.x <= max(p.x, r.x) + 1e-12 &&
           min(p.y, r.y) <= q.y + 1e-12 && q.y <= max(p.y, r.y) + 1e-12;
}

bool segmentsIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    // special cases
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int main() {
    // quick demo
    Point A(0,0), B(4,4), C(0,4), D(4,0);
    cout << "Dist A-B: " << dist(A,B) << "\n";
    cout << "Segments AB and CD intersect? " << (segmentsIntersect(A,B,C,D) ? "YES\n" : "NO\n");
    return 0;
}
