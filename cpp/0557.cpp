class Solution {
private:
    string reverseWord(string s, int left, int right) {
        int len = (right - left + 1) / 2;

        for (int i = 0; i < len; i++) {
            swap(s[left + i], s[right - i]);
        }

        return s;
    }
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.length(); i++) {
            int j = i + 1;

            for (; (j < s.length()) && (s[j] != ' '); j++);

            s = reverseWord(s, i, j - 1);
            i = j;
        }

        return s;
    }
};
