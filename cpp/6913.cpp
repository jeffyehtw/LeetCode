class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ret = -1;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int j = 2;

            if (nums[i] - nums[i + 1] != -1) {
                continue;
            }
            for (; i + j < nums.size(); j++) {
                if ((j % 2 == 0) && (nums[i] != nums[i + j])) {
                    break;
                } else if ((j % 2 == 1) && (nums[i + 1] != nums[i + j])) {
                    break;
                }
            }
            ret = max(ret, j);
        }
        
        return ret;
    }
};
