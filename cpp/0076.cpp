class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int valid = 0;
        int start = 0;
        int len = INT_MAX;
        unordered_map<char, int> umap;

        for (int i = 0; i < t.length(); i++) {
            umap[t[i]]++;
        }

        while (right < s.length()) {
            char c = s[right];

            if (umap.find(c) != umap.end()) {
                umap[c]--;

                if (umap[c] == 0) {
                    valid++;
                }
            }

            while (valid == umap.size()) {
                char c = s[left];

                if (right - left + 1 < len) {
                    start = left;
                    len = right - left + 1;
                }
                if (umap.find(c) != umap.end()) {
                    umap[c]++;
                    if (umap[c] == 1) {
                        valid--;
                    }
                }
                left++;
            }
            right++;
        }

        return (len == INT_MAX) ? "" : string(s, start, len);
    }
};
