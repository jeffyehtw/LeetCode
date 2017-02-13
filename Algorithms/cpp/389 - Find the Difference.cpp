class Solution {
public:
    char findTheDifference(string s, string t) {
        // var
        vector<int> count(26, 0);
        
        // init
        for (int i = 0; i < s.length(); i++)
            count[s[i] - 'a']++;
        
        for (int i = 0; i < t.length(); i++) {
            if (count[t[i] - 'a'] == 0)
                return t[i];
            count[t[i] - 'a']--;
        }
    }
};