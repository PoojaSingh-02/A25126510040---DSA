class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
    }
    void push(int value) {
        st.push(value);
        if (minSt.empty() || value <= minSt.top())
            minSt.push(value);
    }
    void pop() {
        if (st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return minSt.top();
    }
};


<img width="380" height="172" alt="image" src="https://github.com/user-attachments/assets/2c7071e8-4832-4d36-ac0d-a6e088eeda01" />
