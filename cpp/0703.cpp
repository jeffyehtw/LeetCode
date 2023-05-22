class KthLargest {
private:
    int index = -1;
    multiset<int> ms;
public:
    KthLargest(int k, vector<int>& nums) {
        index = k - 1;
        for (int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
        }
    }
    
    int add(int val) {
        ms.insert(val);
        auto it = ms.rbegin();
        for (int i = 0; i < index; i++, it++);
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
