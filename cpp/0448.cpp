class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        vector<bool> seen(nums.size() + 1, false);
        
        for (int i = 0; i < nums.size(); i++) {
            seen[nums[i]] = true;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (seen[i]) {
                continue;
            } else {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
