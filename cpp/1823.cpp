class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> alive(n, true);
        int idx = 0;
        int ret = 0;

        for (int i = 0; i < n - 1; i++) {
            int cnt = 0;
            
            while (true) {
                cnt += alive[idx] ? 1 : 0;
                if (cnt == k) {
                    break;
                }
                idx++;
                idx %= n;
            }
            alive[idx] = false;
        }
        for (int i = 0; i < n; i++) {
            if (alive[i]) {
                ret = i + 1;
                break;
            }
        }

        return ret;
    }
};
