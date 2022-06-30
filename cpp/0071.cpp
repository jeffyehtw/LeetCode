class Solution {
public:
    string simplifyPath(string path) {
        // var 
        string result;
        vector<string> tmp;
        vector<string> splits = split(path, '/');
        
        // run
        for (int i = 0; i < splits.size(); i++) {
            if (splits[i] == ".")
                continue;
            else if (splits[i] == "..") {
                if (!tmp.empty())
                    tmp.pop_back();
            }
            else
                tmp.push_back(splits[i]);
        }
        
        // merge
        for (int i = 0; i < tmp.size(); i++)
            result += "/" + tmp[i];
            
        return result.length() == 0 ? "/" : result;   
    }
    
    vector<string> split(const string &str, const char &delim)
    {
        // var
        string token;
        stringstream ss(str);
        vector<string> result;
        
        // run
        while (getline(ss, token, delim))
        if (token.length() > 0)
            result.push_back(token);
            
        return result;
    }
};