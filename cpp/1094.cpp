class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int sum = 0;
        unordered_map<int, int> umap;
        vector<vector<int>> stops;

        for (int i = 0; i < trips.size(); i++) {
            if (umap.find(trips[i][1]) == umap.end()) {
                stops.push_back({ trips[i][1], 0 });
                umap[trips[i][1]] = stops.size() - 1;
            }
            stops[umap[trips[i][1]]][1] += trips[i][0];
            if (umap.find(trips[i][2]) == umap.end()) {
                stops.push_back({ trips[i][2], 0});
                umap[trips[i][2]] = stops.size() - 1;
            }
            stops[umap[trips[i][2]]][1] -= trips[i][0];
        }
        sort(stops.begin(), stops.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });

        for (int i = 0; i < stops.size(); i++) {
            sum += stops[i][1];
            if (sum > capacity) {
                return false;
            }
            
        }

        return true;
    }
};
