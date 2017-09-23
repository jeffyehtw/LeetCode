class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        // var
        string result;
        vector<string> s;
        vector<string> v[26];
        
        for (int i = 0; i < dict.size(); i++)
            v[dict[i][0] - 'a'].push_back(dict[i]);
        for (int i = 0; i < 26; i++)
            sort(v[i].begin(), v[i].end());
     
        // divide
        for (int i = 0; i < sentence.length(); ) {
            // var
            size_t end = sentence.find(" ", i + 1);
            
            s.push_back(sentence.substr(i, end - i));
            
            if (end == string::npos)
                break;
            
            i = end + 1;
        }
        
        // replace
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < v[s[i][0] - 'a'].size(); j++) {
                // var
                int count = 0;
                for (; count < v[s[i][0] - 'a'][j].length(); count++) {
                    if (s[i][count] != v[s[i][0] - 'a'][j][count])
                        break;
                }
                
                if (count == v[s[i][0] - 'a'][j].length())
                    s[i] = v[s[i][0] - 'a'][j];
            }
        }
        
        // restore
        result = s[0];
        for (int i = 1; i < s.size(); i++)
            result += " " + s[i];
        
        return result;
    }
};