class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ret = 0;
        queue<int> q;
        vector<int> times(n, 0);
        unordered_map<int, vector<int>> umap;

        for (int i = 0; i < manager.size(); i++) {
            if (i == headID) {
                continue;
            }
            if (umap.find(manager[i]) == umap.end()) {
                umap[manager[i]] = vector<int>({ i });
            } else {
                umap[manager[i]].push_back(i);
            }
        }

        q.push(headID);
        while (!q.empty()) {
            auto childs = umap[q.front()];
            for (int i = 0; i < childs.size(); i++) {
                times[childs[i]] = times[q.front()] + informTime[q.front()];
                ret = max(ret, times[childs[i]]);
                q.push(childs[i]);
            }
            q.pop();
        }

        return ret;
    }
};
