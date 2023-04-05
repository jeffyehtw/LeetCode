class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret(nums.begin(), nums.end());
        ret.insert(ret.end(), nums.begin(), nums.end());
        return ret;
    }
};
