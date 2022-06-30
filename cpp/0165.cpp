class Solution {
public:
    int compareVersion(string version1, string version2) {
        // var
        int i = 0;
        int j = 0;
        int m = version1.length();
        int n = version2.length();

        while (i < m || j < n) {
            // var
            int a = 0;
            int b = 0;
            
            for (; i < m && version1[i] != '.'; i++) {
                a *= 10;
                a += version1[i] - '0';
            }
            
            for (; j < n && version2[j] != '.'; j++) {
                b *= 10;
                b += version2[j] - '0';
            }
            
            i += version1[i] == '.';
            j += version2[j] == '.';
            
            if (a != b)
                return a > b ? 1 : -1;
        }
        
        return 0;
    }
};