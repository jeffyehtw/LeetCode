class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // pre
        sort(nums.begin(), nums.end());
        
        // find duplicate
        for (int i = 1; i < nums.size(); i++)
        if (nums[i - 1] == nums[i])
            return true;
            
        return false;
    }
};