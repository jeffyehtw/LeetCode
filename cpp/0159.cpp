class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0;
        int right = 0;
        int ret = 0;
        unordered_map<char, int> umap;

        while (right < s.length()) {
            if (umap.find(s[right]) == umap.end()) {
                umap[s[right]] = 1;
            } else {
                umap[s[right]]++;
            }
            while (umap.size() > 2) {
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
