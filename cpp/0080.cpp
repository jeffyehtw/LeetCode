class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;

        for (int i = 1; i < nums.size(); ) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
                if (cnt >= 3) {
                    nums.erase(nums.begin() + i);
                } else {
                    i++;
                }
            } else {
                cnt = 1;
                i++;
            }
        }

        return nums.size();
    }
};
