class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // pre
        sort(nums.begin(), nums.end());
        
        // run
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i)
                return i;
        return nums.size();
    }
};