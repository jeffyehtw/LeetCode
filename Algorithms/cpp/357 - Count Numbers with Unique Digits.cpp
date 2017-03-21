class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // var
        vector<int> dp{ 1, 10, 91 };
        
        for (int i = 3; i <= n; i++) {
            // var
            int temp = 9;
            
            // init
            dp.push_back(9);
            
            for (int j = 1; j < i; j++) {
                dp[i] *= temp;
                temp--;
            }
            
            dp[i] += dp[i - 1];
        }
        return dp[n];
    }
};