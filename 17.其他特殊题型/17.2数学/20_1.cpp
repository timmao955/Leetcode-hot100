// 二分法求方程的根

#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-6;

double binarysearch(double l, double r, double (*f)(double)) {
    if (f(l) * f(r) > 0) {
        return NAN;
    }
    while ((r - l) > eps) {
        double mid = l + (r - l) / 2.0;
        if (fabs(f(mid)) < eps) {
            return mid;
        } else if (f(l) * f(mid) < 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l + (r - l) / 2.0;
}

double yiyuanerci(double x) {
    return pow(x, 2) - 4;
}

double yiyuansanci(double x) {
    return pow(x, 3) - x - 2;
}

int main() {
    double root1 = binarysearch(0, 5, yiyuanerci);
    double root2 = binarysearch(-5, 0, yiyuanerci);
    cout << root1 << " " << root2 << endl;

    double root3 = binarysearch(1, 2, yiyuansanci);
    cout << root3;

    return 0;
}