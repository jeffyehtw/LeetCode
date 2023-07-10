class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        unordered_map<char, string> fmap;
        unordered_map<string, char> bmap;

        for (int i = 0; i < s.length(); ) {
            int j = i + 1;
            for (; (j < s.length()) && (s[j] != ' '); j++);
            words.push_back(s.substr(i, j - i));
            i = j + 1;
        }
        if (pattern.length() != words.size()) {
            return false;
        }
        for (int i = 0; i < pattern.length(); i++) {
            bool f = fmap.find(pattern[i]) == fmap.end();
            bool b = bmap.find(words[i]) == bmap.end();

            if (f && b) {
                fmap[pattern[i]] = words[i];
                bmap[words[i]] = pattern[i];
            } else if (!f && !b 
                && (fmap[pattern[i]] == words[i]) 
                && (pattern[i] == bmap[words[i]])) {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};
