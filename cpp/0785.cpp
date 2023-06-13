class Solution {
private:
    vector<bool> visited;
    vector<bool> color;
    bool valid = true;
    void traverse(vector<vector<int>>& graph, int idx) {
        if (!valid) {
            return;
        }
        visited[idx] = true;
        for (int i = 0; i < graph[idx].size(); i++) {
            if (!visited[graph[idx][i]]) {
                color[graph[idx][i]] = !color[idx];
                traverse(graph, graph[idx][i]);
            } else if (color[graph[idx][i]] == color[idx]) {
                valid = false;
                break;
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        visited = vector<bool>(graph.size(), false);
        color = vector<bool>(graph.size(), false);
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                traverse(graph, i);
            }
        }
        return valid;
    }
};
