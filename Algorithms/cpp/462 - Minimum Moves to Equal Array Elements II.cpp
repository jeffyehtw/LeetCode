class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // var
        int moves = 0;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++)
            moves += abs(nums[n / 2] - nums[i]);
        
        return moves;
    }
};