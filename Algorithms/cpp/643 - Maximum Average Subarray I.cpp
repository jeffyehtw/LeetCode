class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // var
        double max_val = -10000 * 30001;
        
        // init
        nums.insert(nums.begin(), 0);
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        
        for (int i = 1; i < nums.size() - k + 1; i++)
            max_val = max(max_val, double(nums[i + k - 1] - nums[i - 1]));
            
        return max_val / k;
    }
};