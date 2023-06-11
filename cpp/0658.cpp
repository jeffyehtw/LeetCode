class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ret;
        vector<pair<int, int>> vp;

        for (int i = 0; i < arr.size(); i++) {
            vp.push_back(make_pair(arr[i], abs(arr[i] - x)));
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) {
                return (a.first < b.first);
            } else {
                return (a.second < b.second);
            }
        });
        for (int i = 0; (i < k) && (i < arr.size()); i++) {
            ret.push_back(vp[i].first);
        }
        sort(ret.begin(), ret.end());

        return ret;
    }
};
