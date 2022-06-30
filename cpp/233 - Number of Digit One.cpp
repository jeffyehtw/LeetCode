class Solution {
public:
    int countDigitOne(int n) {
        // var
        int m = n;
        int len = 0;
        vector<int> dp{ 1 };
        long long result = 0;
        
        while (m) {
            len++;
            m /= 10;
        }
        
        for (int i = 1; i < len; i++)
            dp.push_back(dp[i - 1] * 10 + pow(10, i));
        
        for (int i = dp.size() - 1; i > -1; i--) {
            // var
            int num = pow(10, i + 1);
            
            result += (n / num) * dp[i];
            result += (n / num) > 1 ? num : 0;
            result += (n / num) == 1 ? n % num + 1 : 0;
            n %= num;
        }
        result += n > 0;
        return result;
    }
};