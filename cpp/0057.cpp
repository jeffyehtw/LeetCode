class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        vector<pair<int, int>> vp;
        int cur = 0;
        int start = 0;

        if (intervals.size() == 0) {
            ret.push_back(newInterval);
            return ret;
        } else if (newInterval[1] < intervals[0][0]) {
            ret = intervals;
            ret.insert(ret.begin(), newInterval);
            return ret;
        } else if (newInterval[0] > intervals.back()[1]) {
            ret = intervals;
            ret.push_back(newInterval);
            return ret;
        }

        for (int i = 0; i < intervals.size(); i++) {
            vp.push_back(make_pair(intervals[i][0], 1));
            vp.push_back(make_pair(intervals[i][1], -1));
        }
        vp.push_back(make_pair(newInterval[0], 1));
        vp.push_back(make_pair(newInterval[1], -1));
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
            return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first);
        });

        cur = 1;
        start = vp[0].first;
        for (int i = 1; i < vp.size(); i++) {
            cur += vp[i].second;
            if (cur == 0) {
                ret.push_back({ start, vp[i].first });
                start = -1;
            } else if ((cur == 1) && (start == -1)) {
                start = vp[i].first;
            }
        }

        return ret;
    }
};
