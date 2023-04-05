class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        unsigned int n = 1 << nums.size();

        for (int i = 0; i < n; i++) {
            int k = i;
            vector<int> set;

            for (int j = 0; j < nums.size(); j++) {
                if (k & 1) {
                    set.push_back(nums[j]);
                }
                k >>= 1;
            }

            ret.push_back(set);
        }

        return ret;
    }
};
