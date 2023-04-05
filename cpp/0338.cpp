class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;

        for (int i = 0; i <= n; i++) {
            int j = i;
            int cnt = 0;
            while (j > 0) {
                cnt += (j % 2);
                j /= 2;
            }
            ret.push_back(cnt);
        }

        return ret;
    }
};
