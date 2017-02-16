class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // var
        int n = nums.size();
        vector<string> v{ "0", "1" };
        vector<vector<int>> result;
        
        // skip
        if (n == 0)
            return vector<vector<int>>(1, vector<int>{});
        
        // generate
        for (int i = 2; i <= n; i++) {
            // var
            int size = v.size();
                
            for (int j = size - 1; j > -1; j--)
                v.push_back("1" + v[j]);
                
            for (int j = 0; j < size; j++)
                v[j] = "0" + v[j];
        }
        
        // run
        for (int i = 0; i < v.size(); i++) {
            // var
            vector<int> tmp{};
            
            for (int j = 0; j < v[i].length(); j++)
            if (v[i][j] == '1')
                tmp.push_back(nums[j]);
            
            result.push_back(tmp);
        }
        return result;
    }
};