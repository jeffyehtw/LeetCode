class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> umap;

        for (int i = 0; i < arr.size(); i++) {
            umap[2 * arr[i]] = i;
        }
        for (int i = 0; i < arr.size(); i++) {
            if ((umap.find(arr[i]) != umap.end())
                && (umap[arr[i]] != i)) {
                return true;
            }
        }

        return false;
    }
};
