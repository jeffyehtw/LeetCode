class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int product = 1;
        int ret = 0;

        while (right < nums.size()) {
            product *= nums[right];

            while ((product >= k) && (left < right)) {
                product /= nums[left];
                left++;
            }
            if (product < k) {
                ret += right - left + 1;
            }
            right++;
        }
        
        return ret;
    }
};
