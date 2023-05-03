class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ret = 1;
        int base = a % 1337;

        if (a == 1) {
            return ret;
        }

        for (int i = b.size() - 1; i > -1; i--) {
            int next = 1;

            for (int j = 0; j < b[i]; j++) {
                ret *= base;
                ret %= 1337;
            }
            for (int j = 0; j < 10; j++) {
                next *= base;
                next %= 1337;
            }
            base = next;
        }

        return ret;
    }
};
