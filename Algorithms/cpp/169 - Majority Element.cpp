class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // pre
        sort(nums.begin(), nums.end());
        
        // var
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            count = nums[i - 1] == nums[i] ? count + 1 : 1;
            if (count > nums.size() / 2)
                return nums[i];
        }
        return nums[0];
    }
};