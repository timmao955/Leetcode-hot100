// 判断点是否在多边形内（射线法）

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x, y;
    Point (int a, int b) {
        x = a;
        y = b;
    }
};

bool isPointInPolygon(Point& p, vector<Point>& poly) {
    int n = poly.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        Point a = poly[i];
        Point b = poly[(i + 1) % n];

        if (a.y > b.y) {
            swap(a, b);
        }

        if (p.y > a.y && p.y <= b.y && (p.x <= max(a.x, b.x))) {
            double xinters = (p.y - a.y) * (b.x - a.x) / (b.y - a.y) + a.x;
            if (xinters > p.x) {
                cnt++;
            }
        }
    }

    return cnt % 2 == 1;
}

int main() {
    vector<Point> polygon = {
        {0, 0},
        {4, 0},
        {4, 4},
        {0, 4}
    };
    Point testPoint(2, 2);

    if (isPointInPolygon(testPoint, polygon)) {
        cout << "inside";
    } else {
        cout << "outside";
    }

    return 0;
}