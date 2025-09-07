// 交叉熵

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double cross_entropy(const vector<int>& P, const vector<vector<double>>& Q) {
    const double eps = 1e-12;
    int n = P.size();
    double loss = 0.0;

    for (int i = 0; i < n; i++) {
        int label = P[i];
        double prob = max(min(Q[i][label], 1.0 - eps), eps);
        loss += -log(prob);
    }

    return loss / n;
}

int main() {
    vector<int> P = {0, 2, 1};
    vector<vector<double>> Q = {
        {0.7, 0.2, 0.1},
        {0.1, 0.1, 0.8},
        {0.2, 0.6, 0.2}
    };
    double loss = cross_entropy(P, Q);
    cout << loss;

    return 0;
}