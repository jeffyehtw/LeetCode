class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // var
        int val;
        stack<int> tmp;
        
        while (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        
        val = tmp.top();
        tmp.pop();
        
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
        
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        // var
        int val;
        stack<int> tmp;
        
        while (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        
        val = tmp.top();
        
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
        
        return val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
    
    // var
    stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */