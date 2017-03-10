class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // var
        int n = nums.size();
        int front = 1;
        int back = 1;
        vector<int> result(n, 1);
        
        for (int i = 1; i < n; i++) {
            front *= nums[i - 1];
            back *= nums[n - i];
            result[i] *= front;
            result[n - 1 - i] *= back;
        }
        return result;
    }
};