class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // init
        sort(nums.begin(), nums.end());
        
        // var
        int result = 0;
        int mid = nums[nums.size() / 2];
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() / 2)
                continue;
            result += abs(nums[i] - mid);
        }
        return result;
    }
};