class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
            
        // var
        vector<int> v(0);
        
        for (int i = 0; i < nums.size(); i++) {
            // var
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end())
                v.push_back(nums[i]);
            else if (nums[i] < *it)
                *it = nums[i];
        }
        return v.size();
    }
};