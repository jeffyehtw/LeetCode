class Solution {
private:
    bool overlap(vector<int>& a, vector<int>& b) {
        return (((a[0] < b[0]) && (b[0] < a[1]))
                || ((b[0] < a[0]) && (a[0] < b[1])));
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ret = 0;
        int idx = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
        });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[idx][0] == intervals[i][0]) {
                ret++;
            } else if (overlap(intervals[idx], intervals[i])) {
                if (intervals[idx][1] > intervals[i][1]) {
                    idx = i;
                }
                ret++;
            } else {
                idx = i;
            }
        }

        return ret;
    }
};
