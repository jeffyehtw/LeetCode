class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // var
        vector<vector<int>> result;
        int len = pow(2, nums.size());
                      
        for (int i = 0; i < len; i++) {
            // var
            int tmp = i;
            vector<int> v;
            
            for (int j = 0; j < nums.size(); j++) {
                if (tmp & 1)
                    v.push_back(nums[j]);
                tmp >>= 1;
            }
            
            result.push_back(v);
        }
        return result;
    }
};