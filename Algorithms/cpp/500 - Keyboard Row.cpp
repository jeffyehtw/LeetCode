class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // var
        vector<string> result;
        
        for (int i = 0; i < words.size(); i++) {
            // var
            int ok = true;
            int row = find_row(tolower(words[i][0]));
            
            for (int j = 1; j < words[i].length() && ok; j++) {
                if (find_row(tolower(words[i][j])) != row)
                    ok = false;
            }
            
            if (ok)
                result.push_back(words[i]);
        }
        return result;
    }
    
    int find_row(char c) {
        // var
        string rows[3] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        
        for (int i = 0; i < 3; i++) {
            if (rows[i].find(c) != -1)
                return i;
        }
        return -1;
    }
};