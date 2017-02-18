class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // var
        vector<pair<int, int>> p;
        
        // init
        for (int i = 0; i < nums.size(); i++)
            p.push_back(pair<int, int>(nums[i], i));
        
        sort(p.begin(), p.end());
        
        // run
        for (int i = 1; i < p.size(); i++) {
            // var
            bool a = p[i - 1].first == p[i].first;
            bool b = p[i].second - p[i - 1].second <= k;
            
            if (a && b)
                return true;
        }
        return false;
    }
};