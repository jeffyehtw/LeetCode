class Solution {
public:
    int minMoves(vector<int>& nums) {
        // var
        int sum = 0;
        int n = nums.size();
        int min_num = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            min_num = min(min_num, nums[i]);
            sum += nums[i];
        }
        return sum - min_num * n;
    }
};