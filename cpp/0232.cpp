class MyQueue {
private:
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int ret;
        stack<int> tmp;

        while (!st.empty() && st.size() > 1) {
            tmp.push(st.top());
            st.pop();
        }
        ret = st.top();
        st.pop();

        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }

        return ret;
    }
    
    int peek() {
        int ret;
        stack<int> tmp;

        while (!st.empty()) {
            tmp.push(st.top());
            st.pop();
        }
        ret = tmp.top();

        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }

        return ret;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
