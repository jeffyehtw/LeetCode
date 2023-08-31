class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;
        unsigned int alpha = 0;

        for (int i = 0; i < allowed.length(); i++) {
            alpha |= 1 << (allowed[i] - 'a');
        }
        for (int i = 0; i < words.size(); i++) {
            int len = 0;

            for (; len < words[i].length(); len++) {
                if (((alpha >> (words[i][len] - 'a')) & 1) == 0) {
                    break;
                }
            }
            ret += len == words[i].length();
        }

        return ret;
    }
};
