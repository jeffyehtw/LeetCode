class ProductOfNumbers {
private:
    vector<int> v;
public:
    ProductOfNumbers() {
        v.clear();
    }
    
    void add(int num) {
        if (num == 0) {
            v.clear();
        } else {
            v.push_back((v.size() == 0) ? num : num * v.back());
        }
    }
    
    int getProduct(int k) {
        if (k > v.size()) {
            return 0;
        } else if (k == v.size()) {
            return v.back();
        } else {
            return v.back() / v[v.size() - 1 - k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
