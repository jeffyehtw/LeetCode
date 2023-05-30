class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(nums[nums[i]]);
        }
        return ret;
    }
};
