class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // var
        int result = nums[0] == 1;
        int tmp = result;
        
        // run
        for (int i = 1; i < nums.size(); i++) {
            tmp = nums[i] == 0 ? 0 : tmp + 1;
            result = max(result, tmp);
        }
        return result;
    }
};