class Solution {
public:
    bool rotateString(string A, string B) {
        // var
        int idx = 0;
        int n = A.length();
        int m = B.length();
        
        if (n == 0 && m == 0)
            return true;
        
        while (idx < B.length() && A[0] != B[idx])
            idx++;
        if (idx == B.length())
            return false;
        
        while (1) {
            if (A == B.substr(idx) + B.substr(0, idx);
                return true;
            
            idx++;
            
            while (idx < B.length() && A[0] != B[idx])
                idx++;
            if (idx == B.length())
                return false;
        }
        return false;
    }
};
