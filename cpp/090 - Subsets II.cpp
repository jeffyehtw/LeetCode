class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // var
        set<vector<int>> s;
        vector<vector<int>> result(1, vector<int>());
        
        // init
        for (int i = 0; i < nums.size(); i++) {
            int n = result.size();
            
            for (int j = 0; j < n; j++) {
                // fix order
                sort(result[j].begin(), result[j].end());
                
                // add
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
            
            // fix duplicate
            sort(result.begin(), result.end());
            
            // remove duplicate
            for (int j = 1; j < result.size(); ) {
                if (result[j - 1] == result[j])
                    result.erase(result.begin() + j);
                else
                    j++;
            }
        }
        return result;
    }
};