class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // var
        int num = 0;
        int m[256] = { false };
        
        for (int i = 0; i < J.length(); i++)
            m[J[i]]++;
        
        for (int i = 0; i < S.length(); i++)
            num += m[S[i]];
        
        return num;
    }
};
