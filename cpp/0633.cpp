class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<long long, bool> umap;

        if (c <= 1) {
            return true;
        }

        for (unsigned long i = 1; i <= pow(c, 0.5); i++) {
            umap[(unsigned long)c - i * i] = true;
        }
        for (unsigned long  i = 0; i <= pow(c, 0.5); i++) {
            if (umap.find(i * i) != umap.end()) {
                return true;
            }
        }

        return false;
    }
};
