class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ret(2, 0);

        for (int i = 1; i <= pow(area, 0.5); i++) {
            if (area % i == 0) {
                ret[0] = area / i;
                ret[1] = i;
            }
        }

        return ret;
    }
};
