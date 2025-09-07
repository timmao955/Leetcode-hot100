// 牛顿法求方程的根

#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-6;
const int max_iter = 1000;

double newtonmethod(double x0, double (*f)(double), double (*df)(double)) {
    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-12) {
            return NAN; // 导数太小，可能发生除零错误，停止迭代
        }

        double x_next = x - fx / dfx;
        if (fabs(f(x_next)) < eps) {
            return x_next;
        }
        x = x_next;
    }
    return x;
}

double yiyuanerci(double x) {
    return pow(x, 2) - 4;
}
double d_yiyuanerci(double x) {
    return 2 * x;
}

double yiyuansanci(double x) {
    return pow(x, 3) - x - 2;
}
double d_yiyuansanci(double x) {
    return 3 * pow(x, 2) - 1;
}

int main() {
    double root1 = newtonmethod(2, yiyuanerci, d_yiyuanerci);
    double root2 = newtonmethod(-2, yiyuanerci, d_yiyuanerci);
    cout << root1 << " " << root2 << endl;

    double root3 = newtonmethod(1.5, yiyuansanci, d_yiyuansanci);
    cout << root3;

    return 0;
}