class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int right = nums1.size() - 1;
        vector<int> ret(nums2.begin(), nums2.end());
        vector<pair<int, int>> vp;

        for (int i = 0; i < nums2.size(); i++) {
            vp.push_back(make_pair(nums2[i], i));
        }
        sort(nums1.begin(), nums1.end());
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        });

        for (int i = 0; i < vp.size(); i++) {
            if (nums1[right] > vp[i].first) {
                ret[vp[i].second] = nums1[right];
                right--;
            } else {
                ret[vp[i].second] = nums1[left];
                left++;
            }
        }

        return ret;
    }
};
