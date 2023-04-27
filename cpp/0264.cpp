class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        vector<int> ret(1, 1);

        while (ret.size() < n) {
            ret.push_back(
                min(ret[p2] * 2, min(ret[p3] * 3, ret[p5] * 5))
            );
            if (ret.back() == ret[p2] * 2) {
                p2++;
            }
            if (ret.back() == ret[p3] * 3) {
                p3++;
            }
            if (ret.back() == ret[p5] * 5) {
                p5++;
            }
        }

        return ret.back();        
    }
};
