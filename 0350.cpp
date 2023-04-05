class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        vector<int> map(1001, 0);
        
        for (int i = 0; i < nums1.size(); i++) {
            map[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (map[nums2[i]] > 0) {
                map[nums2[i]]--;
                ret.push_back(nums2[i]);
            }
        }

        return ret;
    }
};
