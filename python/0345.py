class Solution {
public:
    bool isVowels(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e'
            || c == 'i' || c == 'o'
            || c == 'u';
    }
    string reverseVowels(string s) {
        vector<char> c;
        for(int i = 0; i < s.length(); i++)
            if(isVowels(s[i]))
                c.push_back(s[i]);      
        for(int i = 0, j = 0; i < s.length(); i++)
        if(isVowels(s[i]))
        {
            s[i] = c;
            j++;
        }
        return s;
    }
};