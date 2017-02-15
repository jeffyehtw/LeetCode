class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // var
        map<int, int> m;
        
        // init
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
        }
        
        // erase duplicates
        for (int i = 0; i < nums.size(); ) {
            if (m[nums[i]] > 2) {
                m[nums[i]]--;
                nums.erase(nums.begin() + i);
            }
            else
                i++;
        }
        return nums.size();
    }
};