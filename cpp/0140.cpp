class Solution {
private:
    vector<string> ret;
    unordered_map<string, int> umap;
    void backtrack(string s, int index, int min, int max, string sentence) {
        if (index == s.length()) {
            ret.push_back(string(sentence, 0, sentence.length() - 1));
            return;
        } else if (index > s.length()) {
            return;
        }

        for (int i = min; (i <= max) && (index + i <= s.length()); i++) {
            string sub(s, index, i);

            if (umap.find(sub) != umap.end()) {
                backtrack(s, index + i, min, max, sentence + sub + " ");
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int max = INT_MIN;
        int min = INT_MAX;

        for (int i = 0; i < wordDict.size(); i++) {
            int len = wordDict[i].length();

            umap[wordDict[i]] = i;
            max = (len > max) ? len : max;
            min = (len < min) ? len : min;
        }
        backtrack(s, 0, min, max, "");

        return ret;
    }
};
