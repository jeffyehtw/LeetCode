bool compare(pair<int, int> x, pair<int, int> y) {
    return x.second == y.second ? x.first < y.first : x.second < y.second;
}

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // var
        vector<int> result;
        vector<pair<int, int>> vp;
        
        for (int i = 0; i < arr.size(); i++)
            vp.push_back(pair<int, int>(arr[i], abs(arr[i] - x)));
        sort(vp.begin(), vp.end(), compare);
        
        for (int i = 0; i < k; i++)
            result.push_back(vp[i].first);
        sort(result.begin(), result.end());
        
        return result;
    }
};