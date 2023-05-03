class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret;
        vector<int> tmp = nums;
        unordered_map<int, int> umap;

        sort(tmp.begin(), tmp.end());
        umap[tmp[0]] = 0;
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] == tmp[i - 1]) {
                continue;
            }
            umap[tmp[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(umap[nums[i]]);
        }

        return ret;
    }
};
