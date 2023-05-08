class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.length();
        vector<int> map({
            0, 1, -1, -1, -1, 
            -1, 9, -1, 8, 6
        });

        for (int i = 0; i <= n / 2; i++) {
            if (map[num[i] - '0'] == num[n - 1 - i] - '0') {
                continue;
            }
            return false;
        }

        return true;
    }
};
