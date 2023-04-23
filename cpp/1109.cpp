class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int sum = 0;
        int idxf = 0;
        int idxl = 0;
        vector<int> ret;
        vector<vector<int>> first(bookings.begin(), bookings.end());
        vector<vector<int>> last(bookings.begin(), bookings.end());

        sort(first.begin(), first.end(), [](vector<int> a, vector<int> b) {
            return (a[0] < b[0]);
        });
        sort(last.begin(), last.end(), [](vector<int> a, vector<int> b) {
            return (a[1] < b[1]);
        });
        for (int i = 1; i <= n; i++) {
            while ((idxf < first.size()) && (first[idxf][0] == i)) {
                sum += first[idxf][2];
                idxf++;
            }
            ret.push_back(sum);
            while ((idxl < last.size()) && (last[idxl][1] == i)) {
                sum -= last[idxl][2];
                idxl++;
            }
        }

        return ret;
    }
};
