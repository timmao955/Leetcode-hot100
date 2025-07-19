// 最小栈

#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> st;
void MinStack() {
    st.emplace(0, INT_MAX); 
}

int getMin() {
    return st.top().second;
}

void push(int val) {
    st.emplace(val, min(getMin(), val));
}

void pop() {
    st.pop();
}

int top() {
    return st.top().first;
}

int main() {
    MinStack();
    push(-2);
    push(0);
    push(-3);
    cout << getMin() << endl;
    pop();
    cout << top() << endl;
    cout << getMin() << endl;
    return 0;
}