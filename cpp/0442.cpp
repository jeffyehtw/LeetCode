class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // var
        map<int, bool> m;
        
        for (int i = 0; i < nums.size();) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = true;
                nums.erase(nums.begin() + i);
            }
            else
                i++;
        }
        return nums;
    }
};