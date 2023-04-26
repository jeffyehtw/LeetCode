class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ret = 0;
        int cnt = 1;
        vector<pair<int, int>> vp;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                cnt++;
            } else {
                vp.push_back(make_pair(nums[i - 1], cnt));
                cnt = 1;
            }
        }
        vp.push_back(make_pair(nums.back(), cnt));
        for (int i = 1; i < vp.size(); i++) {
            if (vp[i - 1].first + 1 == vp[i].first) {
                ret = max(ret, vp[i - 1].second + vp[i].second);
            }
        }

        return ret;
    }
};
