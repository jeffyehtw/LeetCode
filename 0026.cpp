class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        int k = 1;
        
        sort(nums.begin(), nums.end());

        cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (cur != nums[i]) {
                k++;
                cur = nums[i];
            } else {
                nums[i] = INT_MAX;
            }
        }
        sort(nums.begin(), nums.end());


        return k;
    }
};
