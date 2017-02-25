class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // var
        vector<pair<int, int>> result;
        vector<pair<int, pair<int, int>>> v;
        int m = nums1.size() > k ? k : nums1.size();
        int n = nums2.size() > k ? k : nums2.size();
        
        if (!m || !n)
            return result;
        
        // init
        for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            v.push_back(make_pair(nums1[i] + nums2[j], make_pair(nums1[i], nums2[j])));
        
        sort(v.begin(), v.end());
        
        // format
        for (int i = 0; i < (v.size() > k ? k : v.size()); i++)
            result.push_back(v[i].second);
            
        return result;
    }
};