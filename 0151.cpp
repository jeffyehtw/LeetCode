class Solution {
public:
    void reverseWords(string &s) {
        if (s == "")
            return;
            
        s = format(split(s));
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
    
    string format(vector<string> strs) {
        if (strs.size() == 0)
            return "";
            
        // var
        string s = strs.back();
        
        for (int i = strs.size() - 2; i > -1; i--)
            s += " " + strs[i];
            
        return s;
    }
};