class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // var
        vector<int> result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size() && result.size() < 2; ) {
            if (nums[i - 1] != nums[i]) {
                result.push_back(nums[i - 1]);
                i++;
            }
            else
                i += 2;
        }
        
        if (result.size() == 1)
            result.push_back(nums.back());
        
        return result;
    }
};