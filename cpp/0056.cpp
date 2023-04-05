class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < intervals.size(); ) {
            if (i == intervals.size() - 1) {
                break;
            } else if (i < intervals.size() - 1) {
                if (intervals[i][1] >= intervals[i + 1][0]) {
                    intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
                    intervals.erase(intervals.begin() + i + 1);
                } else {
                    i++;
                }
            }
        }

        return intervals;
    }
};
