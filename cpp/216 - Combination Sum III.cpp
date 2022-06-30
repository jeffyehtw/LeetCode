class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        DFS(vector<int>(), k, n, 1);
        return result;
    }
    
    void DFS(vector<int> path, int k, int n, int start) {
        if (path.size() == k && n == 0) {
            result.push_back(path);
            return;
        }
        else if (path.size() > k || n < 0)
            return;
            
        for (int i = start; i < 10; i++) {
            path.push_back(i);
            DFS(path, k, n - i, i + 1);
            path.pop_back();
        }
    }
    
    // var
    vector<vector<int>> result;
};