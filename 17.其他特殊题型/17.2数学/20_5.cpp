// 点到面的距离

#include <iostream>
#include <cmath>
using namespace std;

double pointToPlaneDistance(double x, double y, double z,
                            double A, double B, double C, double D) {
    double numerator = fabs(A * x + B * y + C * z + D);
    double denominator = sqrt(A * A + B * B + C * C);
    return numerator / denominator;
}

int main() {
    // 平面: x + 2y + 3z - 6 = 0
    double A = 1, B = 2, C = 3, D = -6;

    // 点 P(1, 0, 0)
    double x = 1, y = 0, z = 0;

    double distance = pointToPlaneDistance(x, y, z, A, B, C, D);
    cout << "点到平面的距离为: " << distance << endl;

    return 0;
}
