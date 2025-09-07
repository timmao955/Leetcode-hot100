// Djistra(堆优化)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
using namespace std;

class comparator {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N + 1, vector<int>(N + 1, INT_MAX));

    for (int i = 0; i < M; i++) {
        int p1, p2, val;
        cin >> p1 >> p2 >> val;
        map[p1][p2] = val;
    }

    int start = 1, end = N;

    vector<int> min_dist(N + 1, INT_MAX);
    vector<bool> visited(N + 1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

    pq.push(pair<int, int>(start, 0));
    min_dist[start] = 0;

    while (!pq.empty()) {
        // 1. 选择距原点最近且未访问过的节点
        pair<int, int> cur = pq.top();
        pq.pop();
        if (visited[cur.first]) {
            continue;
        }

        // 2. 标记该节点已被访问过
        visited[cur.first] = true;

        // 3. 更新非访问节点到源点的距离(min_dist数组)
        for (int i = 1; i <= min_dist.size(); i++) {
            if (!visited[i] && map[cur.first][i] != INT_MAX && (min_dist[cur.first] + map[cur.first][i] < min_dist[i])) {
                min_dist[i] = min_dist[cur.first] + map[cur.first][i];
                pq.push(pair<int, int>(i, min_dist[i]));
            }
        }
    }

    if (min_dist[end] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_dist[end] << endl;
    }

    return 0;
}