class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size() / 3;
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = 0;
            } 
            umap[nums[i]]++;

            // cout << nums[i] << " " << umap[nums[i]] << endl;
            if (umap[nums[i]] > n) {
                ret.push_back(nums[i]);
                umap[nums[i]] = INT_MIN;
            }
        }

        return ret;
    }
};
