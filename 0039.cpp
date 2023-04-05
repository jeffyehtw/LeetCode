class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() <= 0)
            return result;
            
        // pre
        sort(candidates.begin(), candidates.end());
        
        DFS(vector<int>(), candidates, target, 0);
        
        return result;
    }
    
    void DFS(vector<int> path, vector<int> candidates, int target, int start) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        else if (target < 0)
            return;
        
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            DFS(path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
    
    // var
    vector<vector<int>> result;
};