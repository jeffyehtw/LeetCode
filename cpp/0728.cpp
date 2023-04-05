class Solution {
private:
    bool selfdivid(int n) {
        int m = n;

        while (m > 0) {
            if (m % 10 == 0) {
                return false;
            } else if (n % (m % 10) != 0) {
                return false;
            }
            m /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;

        for (; left <= right; left++) {
            if (selfdivid(left)) {
                ret.push_back(left);
            }    
        }

        return ret;
    }
};
