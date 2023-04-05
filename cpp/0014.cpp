class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        int min = INT_MAX;

        for (int i = 0; i < strs.size(); i++) {
            min = strs[i].length() < min ? strs[i].length() : min;
        }

        for (; idx <= min; idx++) {
            int cnt = 1;
            for (; cnt < strs.size() && strs[0][idx] == strs[cnt][idx]; cnt++);
            if (cnt != strs.size())
                break;
        }

        return idx > 0 ? strs[0].substr(0, idx) : "";
    }
};
