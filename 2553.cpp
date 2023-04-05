class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> sum;
            while (nums[i] > 0) {
                sum.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
            reverse(sum.begin(), sum.end());
            ret.insert(ret.end(), sum.begin(), sum.end());
        }

        return ret;
    }
};
