class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> graph;
    vector<vector<bool>> equals;
    void backtrack(int cur, int idx) {
        if (visited[cur]) {
            return;
        }
        visited[cur] = true;
        equals[cur][idx] = true;
        equals[idx][cur] = true;
        for (int i = 0; i < graph[cur].size(); i++) {
            backtrack(graph[cur][i], idx);
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        graph = vector<vector<int>>(26, vector<int>());
        equals = vector<vector<bool>>(26, vector<bool>(26, false));
        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '=') {
                int src = equations[i][0] - 'a';
                int dst = equations[i][3] - 'a';
                graph[src].push_back(dst);
                graph[dst].push_back(src);
            }
        }
        for (int i = 0; i < 26; i++) {
            visited = vector<bool>(26, false);
            backtrack(i, i);
        }
        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '!') {
                int src = equations[i][0] - 'a';
                int dst = equations[i][3] - 'a';
                if (equals[src][dst] || equals[dst][src]) {
                    return false;
                }
            }
        }

        return true;
    }
};
