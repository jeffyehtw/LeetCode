class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int ret = 0;
        int cur = 0;
        unordered_map<int, int> umap;

        while (right < fruits.size()) {
            if (umap.find(fruits[right]) == umap.end()) {
                umap[fruits[right]] = 1;
            } else {
                umap[fruits[right]]++;
            }
            cur++;

            while (umap.size() > 2) {
                umap[fruits[left]]--;
                if (umap[fruits[left]] == 0) {
                    umap.erase(fruits[left]);
                }
                cur--;
                left++;
            }
            ret = max(ret, cur);
            right++;
        }

        return ret;
    }
};
