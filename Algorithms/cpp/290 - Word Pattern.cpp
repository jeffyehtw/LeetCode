class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // var
        map<string, char> m;
        vector<string> v(26, "");
        vector<string> strs = split(str);
        
        // invalid input
        if (pattern.length() != strs.size())
            return false;
        
        // run
        for (int i = 0; i < pattern.length(); i++) {
            if (v[pattern[i] - 'a'] == "") {
                if (m.find(strs[i]) == m.end()) {
                    v[pattern[i] - 'a'] = strs[i];
                    m[strs[i]] = pattern[i];
                }
                else
                    return false;
            }
            else if (v[pattern[i] - 'a'] != strs[i])
                return false;
        }
        return true;
    }
    
    vector<string> split(string str) {
        // var
        string tmp;
        stringstream ss(str);
        vector<string> result;
        
        while (ss >> tmp) {
            result.push_back(tmp);
            
            if (ss.peek() == ' ')
                ss.ignore();
        }
        return result;
    }
};