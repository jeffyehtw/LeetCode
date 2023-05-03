class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        vector<bool> seen(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            if (seen[nums[i]]) {
                ret.push_back(nums[i]);
            } else {
                seen[nums[i]] = true;
            }
        }

        return ret;
    }
};
