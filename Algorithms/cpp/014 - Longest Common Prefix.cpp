class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1)
            return "";
        else if (strs.size() < 2)
            return strs[0];
        
        // var
        int index;
        string result;
        int max_len = max(strs[0].length(), strs[1].length());
        
        // init
        for (index = 0; index < max_len; index++) {
            if (strs[0][index] != strs[1][index])
                break;
        }
        
        // other strs
        for (int i = 2; i < strs.size(); i++) {
            index = min((int)strs[i].length(), index);
            for (int j = 0; j < index; j++) {
                if (strs[i][j] != strs[0][j]) {
                    index = j - 1 < 0 ? 0 : j;
                    break;
                }
            }
        }
        strs[0].assign(strs[0], 0, index);
        return strs[0];
    }
};