class Solution {
private:
    bool cycled = false;
    vector<bool> path;
    vector<bool> visited;
    vector<int> order;
    void traversal(vector<vector<int>>& graph, int idx) {
        if (path[idx]) {
            cycled = true;
        }
        if (visited[idx] || cycled) {
            return;
        }
        visited[idx] = true;
        path[idx] = true;
        for (int i = 0; i < graph[idx].size(); i++) {
            traversal(graph, graph[idx][i]);
        }
        order.push_back(idx);
        path[idx] = false;
    }
    bool valid(int numCourses, vector<vector<int>>& graph) {
        visited = vector<bool>(numCourses, false);
        path = vector<bool>(numCourses, false);
        for (int i = 0; i < graph.size(); i++) {
            traversal(graph, i);
        }
        return !cycled;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph;

        graph = vector<vector<int>>(numCourses, vector<int>());
        
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        if (!valid(numCourses, graph)) {
            return order;
        }
        reverse(order.begin(), order.end());

        return order;
    }
};
