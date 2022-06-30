class Solution {
public:
    bool detectCapitalUse(string word) {
        // var
        int count = 0;
        int index = -1;
        
        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                index = i;
                count++;
            }
        }
        
        if (count == word.length() || count == 0 || count == 1 && index == 0)
            return true;
        return false;
    }
};