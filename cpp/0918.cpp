class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ret = 0;
        int sum = nums[0];
        vector<int> maxacc(nums.begin(), nums.end());
        vector<int> minacc(nums.begin(), nums.end());
        int _max;
        int _min;

        _max = nums[0];
        _min = nums[0];
        maxacc[0] = _max;
        minacc[0] = _min;
        for (int i = 1; i < nums.size(); i++) {
            if (maxacc[i - 1] >= 0) {
                maxacc[i] = maxacc[i - 1] + nums[i]; 
            }
            if (minacc[i - 1] <= 0) {
                minacc[i] = minacc[i - 1] + nums[i];
            }
            sum += nums[i];
            _max = max(_max, max(nums[i], maxacc[i]));
            _min = min(_min, min(nums[i], minacc[i]));
        }

        if (sum == _min) {
            return _max;
        } else {
            return max(sum, max(sum - _min, _max));
        }
    }
};
