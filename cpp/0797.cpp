class Solution {
private:
    vector<vector<int>> ret;
    vector<int> cur;
    void traversal(vector<vector<int>>& g, int node) {
        cur.push_back(node);
        if (node == g.size() - 1) {
            ret.push_back(cur);
            cur.pop_back();
            return;
        }
        for (int i = 0; i < g[node].size(); i++) {
            traversal(g, g[node][i]);
        }
        cur.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        traversal(graph, 0);
        return ret;
    }
};
