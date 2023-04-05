class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        // var
        int len = 1;
        int _max = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            len = nums[i - 1] >= nums[i] ? 1 : len + 1;
            _max = max(_max, len);
        }
        return _max;
    }
};