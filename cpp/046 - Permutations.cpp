class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {     
        // var
        vector<vector<int>> result;
        
        helper(0, nums, result);
        
        return result;
    }
    
    void helper(int begin, vector<int>& nums, vector<vector<int>>& r) {
        if (begin >= nums.size()) {
            r.push_back(nums);
            return;
        }
        
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            helper(begin + 1, nums, r);
            swap(nums[begin], nums[i]);
        }
    }
};