class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // var
        map<string, int> m;
        vector<vector<string>> result;
        
        for (int i = 0; i < strs.size(); i++) {
            // var
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            
            if (m.find(tmp) == m.end()) {
                // var
                vector<string> v{strs[i]};
                result.push_back(v);
                
                // add mapping
                m[tmp] = result.size() - 1;
            }
            else {
                result[m[tmp]].push_back(strs[i]);
            }
        }
        return result;
    }
};