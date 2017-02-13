class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        // var
        map<int, int> m;
        vector<int> result;
        
        // init
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
            
        // run
        for (int i = 0; i < findNums.size(); i++) {
            // search
            bool is_find = false;
            for (int j = m[findNums[i]] + 1; j < nums.size(); j++) {
                if (nums[j] > findNums[i]) {
                    result.push_back(nums[j]);
                    is_find = true;
                    break;
                }
            }
            if (!is_find)
                result.push_back(-1);
        }
        return result;
    }
};