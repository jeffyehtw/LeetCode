class Solution {
public:
    void reverseWords(vector<char>& s) {
        int left = -1;
        int right = 0;

        reverse(s.begin(), s.end());
        for (; right < s.size(); right++) {
            if (isalpha(s[right]) || isdigit(s[right])) {
                if (left == -1) {
                    left = right;
                }
                continue;
            } else {
                reverse(s.begin() + left, s.begin() + right);
                left = -1;
            }
        }
        reverse(s.begin() + left, s.begin() + right);
    }
};
