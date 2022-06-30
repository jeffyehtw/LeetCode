class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() == 0 || nums.size() * nums[0].size() != r * c) 
            return nums;
        
        // var
        vector<vector<int>> result;
        
        // init
        for (int i = 1; i < nums.size(); i++)
            nums[0].insert(nums[0].end(), nums[i].begin(), nums[i].end());
        
        // reshape
        for (int i = 0; i < r; i++) {
            result.push_back(vector<int>(nums[0].begin(), nums[0].begin() + c));
            nums[0].erase(nums[0].begin(), nums[0].begin() + c);
        }
        return result;
    }
};