class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // var
        int count = 1;
        vector<int> result;
        
        // pre
        sort(nums.begin(), nums.end());
        
        if (nums.size() == 0)
            return vector<int>();
        else if (nums.size() == 1)
            return nums;
        else if (nums.size() == 2)
            result.push_back(nums[0]);
        
        // run
        for (int i = 1; i < nums.size(); i++) {
            count = nums[i - 1] == nums[i] ? count + 1 : 1;
            
            if (count > nums.size() / 3) {
                if (result.size() && result.back() == nums[i])
                    continue;
                else
                    result.push_back(nums[i]);
            }
        }
            
        return result;
    }
};