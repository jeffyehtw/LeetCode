class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // pre
        k %= nums.size();
        
        // run
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.assign(nums.begin(), nums.end() - k);
    }
};