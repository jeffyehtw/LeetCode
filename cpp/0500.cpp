class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // var
        map<char, int> m;
        vector<string> result;
        string keyboards[3] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        
        // init
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < keyboards[i].length(); j++)
                m[keyboards[i][j]] = i;
        
        for (int i = 0; i < words.size(); i++) {
            // var
            bool valid = true;
            
            for (int j = 1; j < words[i].length() && valid; j++)
                if (m[tolower(words[i][0])] != m[tolower(words[i][j])])
                    valid = false;
            
            if (valid)
                result.push_back(words[i]);
        }
        
        return result;
    }
};