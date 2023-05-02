class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ret;
        vector<pair<int, int>> vp;
        unordered_map<int, int> umap;
        vector<int> arr;

        for (int i = 0; i < arr2.size(); i++) {
            umap[arr2[i]] = i;
        }
        for (int i = 0; i < arr1.size(); i++) {
            if (umap.find(arr1[i]) == umap.end()) {
                arr.push_back(arr1[i]);
            } else {
                vp.push_back(make_pair(arr1[i], umap[arr1[i]]));
            }
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        sort(arr.begin(), arr.end());

        for (int i = 0; i < vp.size(); i++) {
            ret.push_back(vp[i].first);
        }
        for (int i = 0; i < arr.size(); i++) {
            ret.push_back(arr[i]);
        }

        return ret;
    }
};
