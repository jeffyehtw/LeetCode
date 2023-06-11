class Solution {
private:
    vector<bool> visited;
    vector<bool> path;
    vector<vector<int>> graph;
    bool looped = false;
    void traversal(vector<vector<int>>& graph, int idx) {
        if (path[idx]) {
            looped = true;
        }
        if (visited[idx] || looped) {
            return;
        }

        visited[idx] = true;
        path[idx] = true;
        for (int i = 0; i < graph[idx].size(); i++) {
            traversal(graph, graph[idx][i]);
        }
        path[idx] = false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        path = vector<bool>(numCourses, false);
        graph = vector<vector<int>>(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            traversal(graph, i);
        }
        return !looped;
    }
};
