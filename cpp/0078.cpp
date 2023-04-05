class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;

        for (int i = 0; i < (1 << nums.size()); i++) {
            int n = i;
            int index = 0;
            vector<int> subset;

            while (n > 0) {
                if (n & 1) {
                    subset.push_back(nums[index]);
                }
                index++;
                n >>= 1;
            }

            ret.push_back(subset);
        }

        return ret;
    }
};