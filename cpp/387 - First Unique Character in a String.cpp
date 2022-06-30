class Solution {
public:
    int firstUniqChar(string s) {
        // var
        vector<int> v(127, 0);
        
        for (int i = 0; i < s.length(); i++)
            v[s[i]]++;
            
        for (int i = 0; i < s.length(); i++)
            if (v[s[i]] == 1)
                return i;
        return -1;
    }
};