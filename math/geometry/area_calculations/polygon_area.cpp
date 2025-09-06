#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

// Shoelace formula for polygon area (vertices in order: cw or ccw)
double polygonArea(const vector<Point> &poly) {
    int n = poly.size();
    if (n < 3) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        sum += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }
    return fabs(sum) / 2.0;
}

// triangle area by coordinates (absolute)
double triangleArea(const Point &a, const Point &b, const Point &c) {
    return fabs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)) / 2.0);
}

int main() {
    vector<Point> poly = {{0,0},{4,0},{4,3},{0,3}}; // rectangle 4x3 => area 12
    cout << "Polygon area: " << polygonArea(poly) << "\n";
    Point A{0,0}, B{4,0}, C{0,3};
    cout << "Triangle area: " << triangleArea(A,B,C) << "\n"; // 6
}
