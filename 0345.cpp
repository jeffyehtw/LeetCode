class Solution {
private:
    bool isvowel(char c) {
        c = tolower(c);
        return ((c == 'a') 
            || (c == 'e')
            || (c == 'i')
            || (c == 'o')
            || (c == 'u'));
    }
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (true) {
            while (left < s.length() && !isvowel(s[left])) {
                left++;
            }
            while (right > -1 && !isvowel(s[right])) {
                right--;
            }

            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            } else {
                break;
            }
        }

        return s;
    }
};
