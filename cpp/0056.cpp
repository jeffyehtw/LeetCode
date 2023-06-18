class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
        });

        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ret.back()[1] >= intervals[i][1]) {
                continue;
            } else if (ret.back()[1] >= intervals[i][0]) {
                ret.back()[1] = intervals[i][1];
            } else {
                ret.push_back(intervals[i]);
            }
        }

        return ret;
    }
};
