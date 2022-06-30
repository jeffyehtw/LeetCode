class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0)
            return result;
            
        DFS(vector<int>(), n, k, 1);
        
        return result;
    }
    
    void DFS(vector<int> path, int n, int k, int start) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        else if (path.size() > k)
            return;
            
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            DFS(path, n, k, i + 1);
            path.pop_back();
        }
    }
    
    // var
    vector<vector<int>> result;
};