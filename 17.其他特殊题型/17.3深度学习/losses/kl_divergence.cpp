// KL散度

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double kl_divergence(const vector<vector<double>>& P, const vector<vector<double>>& Q) {
    const double eps = 1e-12;
    int n = P.size();
    int c = P[0].size();

    double total_kl = 0.0;

    for (int i = 0; i < n; i++) {
        double kl = 0.0;
        for (int j = 0; j < c; j++) {
            double p = max(min(P[i][j], 1.0 - eps), eps);
            double q = max(min(Q[i][j], 1.0 - eps), eps);
            kl += p * log(p / q);
        }
        total_kl += kl;
    }

    return total_kl / n;
}

int main() {
    vector<vector<double>> P = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    };
    vector<vector<double>> Q = {
        {0.7, 0.2, 0.1},
        {0.1, 0.8, 0.1},
        {0.2, 0.2, 0.6}
    };
    double kl = kl_divergence(P, Q);
    cout << kl;

    return 0;
}