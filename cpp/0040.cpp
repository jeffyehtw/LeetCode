class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() <= 0)
            return result;
        
        // pre
        sort(candidates.begin(), candidates.end());
        
        DFS(vector<int>(), candidates, 0, target);
        
        return result;
    }
    
    void DFS(vector<int> path, vector<int> candidates, int start, int target) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        else if (target < 0)
            return;
            
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            DFS(path, candidates, i + 1, target - candidates[i]);
            path.pop_back();
            
            // duplicate
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                i++;
        }
    }
    
    // var
    vector<vector<int>> result;
};