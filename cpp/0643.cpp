class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ret = -DBL_MAX;
        double sum = 0;

        if (nums.size() < k) {
            return ret;
        }

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        ret = max(ret, sum);

        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];
            ret = max(ret, sum);
        }

        return ret / k;
    }
};