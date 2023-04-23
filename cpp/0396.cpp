class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ret = 0;
        int sum = 0;
        int presum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            presum += nums[i];
            sum += i * nums[i];
        }
        ret = sum;
        for (int i = 1; i <= n - 1; i++) {
            sum += presum;
            sum -= n * nums[n - i];
            ret = max(ret, sum);
        }

        return ret;
    }
};
