class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int cur = 0;
        int ret = 0;
        vector<pair<int, int>> vp;

        for (int i = 0; i < intervals.size(); i++) {
            vp.push_back(make_pair(intervals[i][0], 1));
            vp.push_back(make_pair(intervals[i][1], -1));
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
            return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
        });

        for (int i = 0; i < vp.size(); i++) {
            cur += vp[i].second;
            ret = max(ret, cur);
        }

        return ret;
    }
};
