class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int m = version1.length();
        int n = version2.length();
        int v1 = 0;
        int v2 = 0;

        while ((i < m) || (j < n)) {
            v1 = 0;
            v2 = 0;

            while ((i < m) && (isdigit(version1[i]))) {
                v1 *= 10;
                v1 += version1[i] - '0';
                i++;
            }
            while ((j < n) && (isdigit(version2[j]))) {
                v2 *= 10;
                v2 += version2[j] - '0';
                j++;
            }
            if (v1 < v2) {
                return -1;
            } else if (v1 > v2) {
                return 1;
            }
            i++;
            j++;
        }

        return (v1 == v2) ? 0 : ((v1 < v2) ? -1 : 1);
    }
};
