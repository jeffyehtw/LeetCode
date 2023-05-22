class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(a * nums[i] * nums[i] + b * nums[i] + c);
        }
        sort(ret.begin(), ret.end());

        return ret;
    }
};
