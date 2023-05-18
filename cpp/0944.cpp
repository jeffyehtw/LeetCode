class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ret = 0;

        if (strs.size() <= 1) {
            return ret;
        }
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j - 1][i] > strs[j][i]) {
                    ret++;
                    break;
                }
            }
        }

        return ret;
    }
};
