class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x;
        int y;
        double slope;

        if (coordinates[0][0] == coordinates[1][0]) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0] != coordinates[0][0]) {
                    return false;
                }
            }
        } else if (coordinates[0][1] == coordinates[1][1]) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][1] != coordinates[0][1]) {
                    return false;
                }
            }
        } else {
            y = (coordinates[1][1] - coordinates[0][1]);
            x = (coordinates[1][0] - coordinates[0][0]);
            slope = (double)y / x;

            for (int i = 2; i < coordinates.size(); i++) {
                y = (coordinates[i][1] - coordinates[0][1]);
                x = (coordinates[i][0] - coordinates[0][0]);
                double tmp = (double)y / x;

                if (tmp != slope) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
