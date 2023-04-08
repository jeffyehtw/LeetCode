class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min = INT_MAX;
        int idx = -1;

        for (int i = 0; i < points.size(); i++) {
            int d = 0;
            if (points[i][0] == x) {
                d = abs(points[i][1] - y);
                if (min > d) {
                    min = d;
                    idx = i;
                }
            } else if (points[i][1] == y) {
                d = abs(points[i][0] - x);
                if (min > d) {
                    min = d;
                    idx = i;
                }
            }
        }

        return idx;
    }
};
