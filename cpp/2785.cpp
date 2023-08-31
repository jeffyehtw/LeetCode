class Solution {
private:
    bool isVowels(char c) {
        c = tolower(c);
        return ((c == 'a') 
            || (c == 'e') 
            || (c == 'i')
            || (c == 'o')
            || (c == 'u'));
    }
public:
    string sortVowels(string s) {
        int idx = 0;
        vector<char> vowels;
        
        for (int i = 0; i < s.length(); i++) {
            if (isVowels(s[i])) {
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());

        for (int i = 0; i < s.length(); i++) {
            if (isVowels(s[i])) {
                s[i] = vowels[idx];
                idx++;
            }
        }
        
        return s;
    }
};
