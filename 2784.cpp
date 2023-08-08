class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        if (n == 1) {
            return false;
        } else if (n != nums.back() + 1) {
            return false;
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        
        return (nums[n - 2] == nums[n - 1]);
    }
};
