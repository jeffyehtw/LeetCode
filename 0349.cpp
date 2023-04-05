class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> map(1001, false);
        vector<int> ret;

        for (int i = 0; i < nums1.size(); i++) {
            map[nums1[i]] = true;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (map[nums2[i]]) {
                ret.push_back(nums2[i]);
                map[nums2[i]] = false;
            }
        }

        return ret;
    }
};
