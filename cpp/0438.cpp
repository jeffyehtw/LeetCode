class Solution {
private:
    bool isanagram(vector<int> s, vector<int> p) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != p[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        vector<int> pcnt(26, 0);
        vector<int> scnt(26, 0);

        if (p.length() > s.length()) {
            return ret;
        }

        for (int i = 0; i < p.length(); i++) {
            pcnt[p[i] - 'a']++;
            scnt[s[i] - 'a']++;
        }

        if (isanagram(pcnt, scnt)) {
            ret.push_back(0);
        }

        for (int i = 1; i < s.length() - p.length() + 1; i++) {
            scnt[s[i - 1] - 'a']--;
            scnt[s[i + p.length() - 1] - 'a']++;

            if (isanagram(pcnt, scnt)) {
                ret.push_back(i);
                // cout << i << endl;
            }
        }

        return ret;
    }
};
