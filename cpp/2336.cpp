class SmallestInfiniteSet {
private:
    multiset<int> ms;
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            ms.insert(i);
        }
    }
    
    int popSmallest() {
        int ret = *(ms.begin());
        ms.erase(ms.begin());
        return ret;
    }
    
    void addBack(int num) {
        if (ms.find(num) == ms.end()) {
            ms.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
