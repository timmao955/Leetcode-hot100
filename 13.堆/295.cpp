// 数据流的中位数

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>> A;
priority_queue<int, vector<int>, greater<int>> B;

void MedianFinder() {
        
}

void addNum(int num) {
    if (A.size() == B.size()) {
        A.push(num);
        B.push(A.top());
        A.pop();
    } else {
        B.push(num);
        A.push(B.top());
        B.pop();
    }
}

double findMedian() {
    return A.size() == B.size() ? (A.top() + B.top()) / 2.0 : B.top();
}

int main() {
    addNum(1);
    addNum(2);
    cout << findMedian() << endl;
    addNum(3);
    cout << findMedian();
    return 0;
}