class MinStack {
private:
    int _min;
    vector<int> _v;
public:
    /** initialize your data structure here. */
    MinStack() {
        _min = INT_MAX;
    }

    void push(int x) {
        _v.push_back(x);
        _min = min(_min, x);
    }

    void pop() {
        if (_v.back() == _min) {
            _min = INT_MAX;
            for (int i = 0; i < _v.size() - 1; i++)
                _min = min(_min, _v[i]);
        }
        _v.pop_back();
    }

    int top() {
        return _v.back();
    }

    int getMin() {
        return _min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
