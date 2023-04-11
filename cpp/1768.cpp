class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        string ret(m + n, ' ');
        int i = 0;
        int j = 0;
        int k = 0;

        while ((j < m) && (k < n)) {
            if (i % 2 == 0) {
                ret[i] = word1[j];
                j++;
            } else {
                ret[i] = word2[k];
                k++;
            }
            i++;
        }
        while (j < m) {
            ret[i] = word1[j];
            i++;
            j++;
        }
        while (k < n) {
            ret[i] = word2[k];
            i++;
            k++;
        }

        return ret;
    }
};
