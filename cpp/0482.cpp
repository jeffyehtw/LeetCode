class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        // var
        int num;
        int index = S.find('-');
        
        // remove '-'
        for (int i = 0; i < S.length(); ) {
            // format
            S[i] = isalpha(S[i]) ? toupper(S[i]) : S[i];
            
            if (S[i] == '-')
                S.erase(S.begin() + i);
            else
                i++;
        }
        
        num = ceil(double(S.length()) / K);
        for (int i = 0; i < num - 1; i++) {
            S.insert(S.end() - K * (i + 1) - i, '-');
        }
        
        return S;
    }
};