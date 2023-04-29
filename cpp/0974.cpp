class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ret = 0;
        int presum = 0;
        vector<int> cnt(k, 0);

        cnt[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            presum += (nums[i] % k + k);
            presum %= k;
            ret += cnt[presum];
            cnt[presum]++;
        }

        return ret;
    }
};
