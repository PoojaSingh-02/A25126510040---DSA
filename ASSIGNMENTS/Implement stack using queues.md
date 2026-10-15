#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
    }
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    int top() {
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};


<img width="380" height="187" alt="image" src="https://github.com/user-attachments/assets/d837c0e3-e4a3-4a45-be69-8aacd2fc175b" />

