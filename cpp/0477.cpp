class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // var
        int result = 0;
        int n = nums.size();
        
        for (int i = 0; i < 32; i++) {
            // var
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += nums[j] & 1;
                nums[j] >>= 1;
            }
            result += tmp * (n - tmp);
        }
        return result;
    }
};