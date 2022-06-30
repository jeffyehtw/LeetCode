class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        if (S.length() == 0)
            return vector<int>({ 0, 0 });
        
        // var
        int num = 0;
        int capacity = 0;
        
        for (int i = 0; i < S.length(); i++) {
            capacity += widths[S[i] - 'a'];
            
            if (capacity > 100) {
                capacity = widths[S[i] - 'a'];
                num++;
            }
        }
        
        num += capacity > 0;
        
        return vector<int>({ num, capacity });
    }
};
