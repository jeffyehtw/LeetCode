class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> map = {
            "", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        for (int i = 0; i < digits.length(); i++) {
            string s = map[digits[i] - '0'];

            if (ret.size() == 0) {
                for (int j = 0; j < s.length(); j++) {
                    ret.push_back(string(1, (s[j])));
                }
            } else {
                int n = ret.size();
                for (int j = 0; j < n; j++) {
                    for (int k = 1; k < s.length(); k++) {
                        ret.push_back(ret[j] + string(1, (s[k])));
                    }
                }
                for (int j = 0; j < n; j++) {
                    ret[j] += string(1, (s[0]));
                }
            }
        }

        return ret;
    }
};
