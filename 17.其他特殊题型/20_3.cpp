// 点到线段的投影点和距离

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

pair<Point, double> project(Point A, Point B, Point P) {
    double dx = B.x - A.x;
    double dy = B.y - A.y;
    double len_AB = pow(dx, 2) + pow(dy, 2);
    double t = ((P.x - A.x) * dx + (P.y - A.y) * dy) / len_AB;

    Point Q;
    if (t < 0.0) {
        Q = A;
    } else if (t > 1.0) {
        Q = B;
    } else {
        Q = {A.x + t * dx, A.y + t * dy};
    }

    double dist = hypot(P.x - Q.x, P.y - Q.y);
    return {Q, dist};
}

int main() {
    Point P = {2, 3};
    Point A = {0, 0};
    Point B = {4, 0};
    auto [Q, dist] = project(A, B, P);
    cout << Q.x << " " << Q.y << endl;
    cout << dist;
    return 0;
}