class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        // var
        int cache[26];
        vector<string> tmp;
        string result = "";
        
        // init
        for (int i = 0; i < 26; i++)
            cache[i] = INT_MAX;
        sort(dict.begin(), dict.end());
        
        // remove duplicate
        for (int i = 0; i < dict.size(); i++) {
            for (int j = i + 1; j < dict.size(); ) {
                if (dict[i] == dict[j].substr(0, dict[i].length()))
                    dict.erase(dict.begin() + j);
                else
                    break;
            }
        }
        
        // cache by first char
        for (int i = 0; i < dict.size(); i++) {
            cache[dict[i][0] - 'a'] = min(cache[dict[i][0] - 'a'], i);
        }
        
        // to vector
        istringstream iss(sentence);
        for(string s; iss >> s; )
            tmp.push_back(s);
        
        // replace
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = cache[tmp[i][0] - 'a']; j < dict.size(); j++) {
                if (tmp[i][0] != dict[j][0])
                    break;
                
                if (tmp[i].substr(0, dict[j].length()) == dict[j]) {
                    tmp[i] = dict[j];
                    break;
                }
            }
        }
        
        // restore from vector
        for (int i = 0; i < tmp.size(); i++)
            result += " " + tmp[i];
        
        return result[0] == ' ' ? result.substr(1) : result;
    }
};