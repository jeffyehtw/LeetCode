class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        int j = 0;
        vector<string> ret;
        
        for (i = 0; i < nums.size(); ) {
            for (j = i + 1; j < nums.size() && nums[j] == nums[j - 1] + 1; j++);
            if (j - i > 1) {
                ret.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            } else {
                ret.push_back(to_string(nums[i]));
            }
            i = j;
        }

        return ret;
    }
};
