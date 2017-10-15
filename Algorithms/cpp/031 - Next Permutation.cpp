class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        
        // var
        int n = nums.size();
        
        for (int i = n - 2; i > -1; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = n - 1; j >= i; j--) {
                    if (nums[i] < nums[j]) {
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};