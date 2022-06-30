class Solution {
public:
    string reverseVowels(string s) {
        // var
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            for (; left < s.length(), !is_vowel(s[left]); left++);
            for (; right > -1, !is_vowel(s[right]); right--);
            
            if (left < right)
                swap(s[left++], s[right--]);
        }
        return s;
    }
    
    bool is_vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i'
        || c == 'o' || c == 'u';
    }
};