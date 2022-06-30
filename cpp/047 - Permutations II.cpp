class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // var
        map<vector<int>, bool> m;
        vector<vector<int>> result;
        
        helper(0, nums, m, result);
        
        return result;
    }
    
    void helper(int begin, vector<int>& nums, map<vector<int>, bool>& m, vector<vector<int>>& r) {
        if (begin >= nums.size()) {
            if (!m[nums]) {
                m[nums] = true;
                r.push_back(nums);
            }
            return;
        }
        
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            helper(begin + 1, nums, m, r);
            swap(nums[begin], nums[i]);
        }
    }
};