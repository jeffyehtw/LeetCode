class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // var
        map<int, int> m;
        int max_count = 1;
        int max_index = 0;
        
        // init
        m[nums[0]]++;
        
        for (int i = 1; i < nums.size(); i++) {
            m[nums[i]]++;
            if (m[nums[i]] > max_count) {
                max_count = m[nums[i]];
                max_index = i;
            }
        }
        return nums[max_index];
    }
};