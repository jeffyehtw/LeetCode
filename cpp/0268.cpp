class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            ret ^= i;
            ret ^= nums[i];
        }
        ret ^= nums.size();

        return ret;
    }
};
