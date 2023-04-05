class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> sv;
        unsigned int n = 1 << nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int j = i;
            vector<int> subset;
            for (int k = 0; k < nums.size() && j > 0; k++, j >>= 1) {
                if (j & 1) {
                    subset.push_back(nums[k]);
                }
            }
            sv.insert(subset);
        }

        return vector<vector<int>>(sv.begin(), sv.end());
    }
};
