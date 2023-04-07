class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int left = 1;
        int right = 1;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        left *= nums[n - 3];
        left *= nums[n - 2];
        left *= nums[n - 1];

        right *= nums[0];
        right *= nums[1];
        right *= nums[n - 1];

        return max(left, right);
    }
};
