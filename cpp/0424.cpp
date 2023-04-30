class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int ret = INT_MIN;
        int _max = INT_MIN;
        char c;
        unordered_map<char, int> umap;

        while (right < s.length()) {
            if (umap.find(s[right]) == umap.end()) {
                umap[s[right]] = 1;
            } else {
                umap[s[right]]++;
            }

            if (umap[s[right]] > _max) {
                c = s[right];
                _max = umap[s[right]];
            }
            if (right - left + 1 - umap[c] > k) {
                umap[s[left]]--;
                if (umap[s[left]] == 0) {
                    umap.erase(s[left]);
                }
                left++;
            }
            ret = max(ret, right - left + 1);
            right++;
        }

        return ret;
    }
};
