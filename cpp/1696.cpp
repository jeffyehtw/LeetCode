class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> dp(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            dp[i] += (ms.empty() ? 0 : *(ms.rbegin()));
            ms.insert(dp[i]);
            if (ms.size() > k) {
                ms.erase(ms.find(dp[i - k]));
            }
        }

        return dp.back();
    }
};
