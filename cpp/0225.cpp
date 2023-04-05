class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int ret;
        queue<int> tmp;

        while (!q.empty() && q.size() > 1) {
            tmp.push(q.front());
            q.pop();
        }
        ret = q.front();
        q.pop();
        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }

        return ret;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
