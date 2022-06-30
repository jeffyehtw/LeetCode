class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // var
        int result = 0;
        vector<int> sum(32, 0);
        
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            for (int j = 0; j < nums.size(); j++)
                sum[i] += nums[j] & mask ? 1 : 0;
        }
        
        for (int i = 32 - 1; i > -1; i--)
            result = (result << 1) + (sum[i] % 3);
        
        return result;
    }
};