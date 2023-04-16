class MyCircularQueue {
private:
    vector<int> v;
    int front;
    int back;
public:
    MyCircularQueue(int k) {
        v = vector<int>(k, -1);
        front = 0;
        back = 0;
    }
    
    bool enQueue(int value) {
        if (v[back] != -1) {
            return false;
        }
        v[back] = value;
        back = (back + 1) % v.size();
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        v[front] = -1;
        front = (front + 1) % v.size();
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return v[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        if (back - 1 < 0) {
            return v[v.size() - 1];
        } else {
            return v[back - 1];
        }
    }
    
    bool isEmpty() {
        return (front == back) && (v[front] == -1);
    }
    
    bool isFull() {
        return (front == back) && (v[front] != -1);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
