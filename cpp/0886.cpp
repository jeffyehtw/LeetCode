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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph;

        visited = vector<bool>(n + 1, false);
        color = vector<bool>(n + 1, false);
        graph = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for (int i = 1 ; i < n + 1; i++) {
            if (!visited[i]) {
                traverse(graph, i);
            }
        }

        return valid;
    }
};
