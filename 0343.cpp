class Solution {
public:
    int integerBreak(int n) {
        // var
        vector<int> v { 0, 0, 1, 2, 4, 6, 9 };
        
        if (n < 7)
            return v[n];
            
        for (int i = 7; i <= n; i++) {
            v.push_back(v[i - 3] * 3);
        }
        
        return v[n];
    }
};