class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> graph;
    void traverse(int idx) {
        if (visited[idx]) {
            return;
        }
        visited[idx] = true;
        for (int i = 0; i < graph[idx].size(); i++) {
            traverse(graph[idx][i]);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ret = 0;
        
        visited = vector<bool>(n, false);
        graph = vector<vector<int>>(n, vector<int>());

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ret++;
                traverse(i);
            }
        }

        return ret;
    }
};
