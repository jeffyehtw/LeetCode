class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // tag
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * -1;
        }
        
        // fix
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                nums[i] = i + 1;
        
        // remove
        for (int i = 0; i < nums.size();) {
            if (nums[i] < 0)
                nums.erase(nums.begin() + i);
            else
                i++;
        }
        return nums;
    }
};