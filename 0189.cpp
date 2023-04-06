class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> rotate;
        
        k %= nums.size();
        rotate = vector<int>(nums.end() - k, nums.end());

        nums.insert(nums.begin(), rotate.begin(), rotate.end());
        nums.erase(nums.end() - rotate.size(), nums.end());
    }
};
