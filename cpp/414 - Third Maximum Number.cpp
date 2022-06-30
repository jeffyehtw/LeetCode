class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> sorted(s.begin(), s.end());
        sort(sorted.begin(), sorted.end());
       
        int n = sorted.size();
        if (n >= 3)
            return sorted[n - 1 - 2];
        else
            return sorted[n - 1];
    }
};