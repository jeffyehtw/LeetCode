class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // var
        set<vector<int>> s;
        vector<vector<int>> v;
        
        // init
        sort(nums.begin(), nums.end());
        
        v.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            if (s.find(nums) == s.end()) {
                s.insert(nums);
                v.push_back(nums);
            }
        }
        return v;
    }
};