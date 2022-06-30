bool compare(pair<int, int> x, pair<int, int> y) {
    return x.second > y.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // init
        sort(nums.begin(), nums.end());
        
        // var
        vector<int> result;
        vector<pair<int, int>> v(1, pair<int, int>(nums[0], 1));
        
        for (int i = 1; i < nums.size(); i++) {
            if (v[v.size() - 1].first != nums[i])
                v.push_back(pair<int, int>(nums[i], 1));
            else
                v[v.size() - 1].second++;
        }
        
        sort(v.begin(), v.end(), compare);
        
        // format
        for (int i = 0; i < k; i++)
            result.push_back(v[i].first);

        return result;
    }
};