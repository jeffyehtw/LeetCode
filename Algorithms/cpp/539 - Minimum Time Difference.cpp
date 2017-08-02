class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // var
        vector<int> tmp;
        int n = timePoints.size();
        int result = INT_MAX;
        
        // init
        for (int i = 0; i < n; i++)
            tmp.push_back(to_minutes(timePoints[i]));
        
        sort(tmp.begin(), tmp.end());
        
        for (int i = 0; i < n - 1; i++) {
            result = min(result, min(tmp[i + 1] - tmp[i], tmp[i] + 60 * 24 - tmp[i + 1]));
        }
        
        return min(result, tmp[0] + 60 * 24 - tmp[n - 1]);
    }
private:
    int to_minutes(string s) {
        // var
        string hour = s.substr(0, 2);
        string minute = s.substr(3, 2);
        return stoi(hour) * 60 + stoi(minute);
    }
};