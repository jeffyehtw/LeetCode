class NumArray {
private:
    vector<int> acc;
public:
    NumArray(vector<int>& nums) {
        acc = vector<int>(nums.size(), 0);

        acc[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            acc[i] = acc[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return acc[right] - ((left > 0) ? acc[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
