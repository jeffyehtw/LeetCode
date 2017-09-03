class Solution {
public:
    bool judgeSquareSum(int c) {
        // var
        map<int, bool> m;
        
        for (int i = 0; i <= pow(c, 0.5) + 1; i++) {
            m[i * i] = true; 
            if (m[c - i * i])
                return true;
        }
        return false;
    }
};