class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ret;
        vector<pair<int, int>> vp;

        for (int i = 0; i < arr.size(); i++) {
            int cnt = 0;
            int tmp = arr[i];

            while (tmp > 0) {
                cnt += tmp & 1;
                tmp >>= 1;
            }
            vp.push_back(make_pair(arr[i], cnt));
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
            return (a.second == b.second) ? a < b : a.second < b.second;
        });
        for (int i = 0; i < vp.size(); i++) {
            ret.push_back(vp[i].first);
        }

        return ret;
    }
};
