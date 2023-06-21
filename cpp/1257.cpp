class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        vector<string> s;
        unordered_map<string, int> pos;
        unordered_map<string, int> parent;
        unordered_map<int, bool> path;
        int idx;

        for (int i = 0; i < regions.size(); i++) {
            for (int j = 0; j < regions[i].size(); j++) {
                if (pos.find(regions[i][j]) == pos.end()) {
                    s.push_back(regions[i][j]);
                    pos[regions[i][j]] = s.size() - 1;
                }
                if (j > 0) {
                    parent[regions[i][j]] = pos[regions[i][0]];
                }
            }
        }

        while (true) {
            path[pos[region1]] = true;
            if (parent.find(region1) == parent.end()) {
                break;
            }
            idx = parent[region1];
            region1 = s[idx];
        }
        while (true) {
            idx = pos[region2];
            if (path.find(idx) != path.end()) {
                return s[idx];
            }
            idx = parent[region2];
            region2 = s[idx];
        }

        return "";
    }
};
