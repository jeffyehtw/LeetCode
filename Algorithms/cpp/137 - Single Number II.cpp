class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // pre
        sort(nums.begin(), nums.end());
        
        // run
        for (int i = 0; i < nums.size() - 2; i += 3)
        if (nums[i] != nums[i + 1])
            return nums[i];
            
        return nums[nums.size() - 1];
    }
};