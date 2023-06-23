class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> lessq;
    priority_queue<int, vector<int>, less<int>> greatq;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (lessq.size() >= greatq.size()) {
            lessq.push(num);
            greatq.push(lessq.top());
            lessq.pop();
        } else {
            greatq.push(num);
            lessq.push(greatq.top());
            greatq.pop();
        }
    }
    
    double findMedian() {
        if (lessq.size() != greatq.size()) {
            return greatq.top() / 1.0;
        } else {
            return (lessq.top() + greatq.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
