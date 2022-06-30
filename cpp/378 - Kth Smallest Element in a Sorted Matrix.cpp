class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // var
        vector<int> flat;
        
        for (int i = 0; i < matrix.size(); i++)
            flat.insert(flat.end(), matrix[i].begin(), matrix[i].end());
            
        sort(flat.begin(), flat.end());
        
        return flat[k - 1];
    }
};