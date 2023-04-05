class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> c(26, 0);

        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            c[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            c[magazine[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (c[i] > 0) {
                return false;
            }
        }

        return true;
    }
};
