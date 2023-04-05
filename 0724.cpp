class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> acc(nums.size(), 0);

        acc[0] = nums[0];
        for (int i = 1; i < acc.size(); i++) {
            acc[i] = acc[i - 1] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            int left = (i > 0) ? acc[i - 1] : 0;
            int right = acc.back() - acc[i];
            
            if (left == right) {
                return i;
            }
        }

        return -1;
    }
};
