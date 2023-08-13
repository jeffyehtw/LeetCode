class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n = names.size();
        unordered_map<string, int> used;
        vector<string> ret(n, "");

        for (int i = 0; i < n; i++) {
            if (used.find(names[i]) == used.end()) {
                used[names[i]] = 1;
                ret[i] = names[i];
            } else {
                bool added = false;
                int idx = used[names[i]];

                for (int j = idx; !added; j++) {
                    string r = names[i] + "(" + to_string(j) + ")";

                    if (used.find(r) == used.end()) {
                        added = true;
                        ret[i] = r;
                        used[r] = 1;
                    }
                    
                    used[names[i]] = j;
                }
                
            }
        }

        return ret;
    }
};
