class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, INT_MAX);

        cnt[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; (j <= nums[i]) && (i + j < n); j++) {
                cnt[i + j] = min(cnt[i] + 1, cnt[i + j]);
            }
        }

        return cnt.back();
    }
};
