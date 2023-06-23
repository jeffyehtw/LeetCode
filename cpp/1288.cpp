class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ret = 0;
        int idx = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
        });
        for (int i = 1; i < intervals.size(); i++) {
            if ((intervals[idx][0] <= intervals[i][0])
                && (intervals[idx][1] >= intervals[i][1])) {
                ret++;
            } else {
                idx = i;
            }
        }

        return intervals.size() - ret;
    }
};
