class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> umap;

        for (int i = 0; i < nums2.size(); i++) {
            umap[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++) {
            int idx = umap[nums1[i]];

            for (; idx < nums2.size(); idx++) {
                if (nums1[i] < nums2[idx]) {
                    ret.push_back(nums2[idx]);
                    break;
                }
            }

            if (idx == nums2.size()) {
                ret.push_back(-1);
            }
        }

        return ret;
    }
};
