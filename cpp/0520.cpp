class Solution {
private:
    bool isCapital(char c) {
        return (c >= 'A') && (c <= 'Z');
    }
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        bool first = isCapital(word[0]);

        for (int i = 0; i < word.length(); i++) {
            if (isCapital(word[i])) {
                cnt++;
            }
        }

        if (first) {
            return (cnt == word.length() || cnt == 1);
        } else {
            return cnt == 0;
        }
    }
};
