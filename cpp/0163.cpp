class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ret;
        int left = lower - 1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (left > nums[i]) {
                continue;
            } else if (left + 1 == nums[i]) {
                left = nums[i];
            } else if (nums[i] > left) {
                ret.push_back({ left + 1, nums[i] - 1 });
                left = nums[i];
            }
        }
        if (left < upper) {
            ret.push_back({ left + 1, upper });
        }
        
        return ret;
    }
};
