class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>({ INT_MAX, 1, -1 }));
        int max = 1;
        int idx = 1;

        if (nums.size() <= 1) {
            return nums;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            dp[i][0] = nums[i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[i] % dp[j][0] == 0)
                    && (dp[i][1] < dp[j][1] + 1)) {
                    dp[i][0] = lcm(nums[i], dp[j][0]);
                    dp[i][1] = dp[j][1] + 1;
                    dp[i][2] = j;
                }
            }
            if (dp[i][1] > max) {
                max = dp[i][1];
                idx = i;
            }
        }
        while (idx >= 0) {
            ret.push_back(nums[idx]);
            idx = dp[idx][2];
        }

        return ret;
    }
};
