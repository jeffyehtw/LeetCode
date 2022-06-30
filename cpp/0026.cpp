class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // var
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] == nums[i + 1] && i < nums.size() - 1) {
                nums.erase(nums.begin() + i);
            }
            else
                i++;
        }
        return nums.size();
    }
};