class Solution {
public:
    string decodeString(string s) {
        // var
        smatch sm;
        regex e("[0-9]+\[[a-z]+\]");
        
        while (regex_search(s, sm, e)) {
            // var
            string tmp = sm[0];
            pair<int, string> obj = parse(tmp);
            string target = "";
            
            // init
            for (int i = 0; i < obj.first; i++)
                target += obj.second;
            
            s.replace(s.find(tmp), tmp.length(), target);
        }    
        return s;
    }
private:
    pair<int, string> parse(string s) {
        // var
        int i = s.find('[');
        
        return pair<int, string>(
            stoi(s.substr(0, i)), 
            s.substr(i + 1, s.length() - (i + 1) - 1)
        );
    }
};