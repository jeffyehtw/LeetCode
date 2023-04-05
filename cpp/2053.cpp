class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int cnt = 0;
        unordered_map<string, int> umap;

        for (int i = 0; i < arr.size(); i++) {
            if (umap.find(arr[i]) == umap.end()) {
                umap[arr[i]] = 0;
            }
            umap[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (umap[arr[i]] == 1) {
                cnt++;
                if (cnt == k) {
                    return arr[i];
                }
            }
        }

        return "";
    }
};
