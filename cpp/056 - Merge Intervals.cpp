/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool compare(Interval x, Interval y) {
     return x.start < y.start;
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0)
            return vector<Interval>();
        
        sort(intervals.begin(), intervals.end(), compare);
        
        // var
        vector<Interval> result{ intervals.front() };
        
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back().end < intervals[i].start)
                result.push_back(intervals[i]);
            else
                result.back().end = max(result.back().end, intervals[i].end);
        }
        return result;
    }
};