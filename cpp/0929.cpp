class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> umap;

        for (int i = 0; i < emails.size(); i++) {
            int idx = 0;
            string s = "";

            for (; idx < emails[i].length(); idx++) {
                if (emails[i][idx] == '+') {
                    break;
                } else if (isalpha(emails[i][idx])) {
                    s += string(1, emails[i][idx]);
                } else if (emails[i][idx] == '.') {
                    continue;
                } else {
                    break;
                }
            }
            for (; (idx < emails[i].length()) && (emails[i][idx] != '@'); idx++);
            s += string(emails[i], idx, emails[i].length() - idx - 1);

            if (umap.find(s) == umap.end()) {
                umap[s] = umap.size();
            }
        }

        return umap.size();
    }
};
