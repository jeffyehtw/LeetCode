class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // var
        int sum = 0;
        
        // init
        sort(nums.begin(), nums.end());
        
        // count
        for(int i = 0; i < nums.size() - 1; i += 2) {
            sum += min(nums[i], nums[i + 1]);
        }
        
        return sum;
    }
};