/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // var
        vector<int> result;
        
        traversal(root, 0);
        
        // format
        for (int i = 0; i < levels.size(); i++)
            result.push_back(levels[i].back());
        
        return result;
    }
    
    void traversal(TreeNode* root, int level) {
        if (!root)
            return;
            
        if (levels.empty() || level > levels.size() - 1)
            levels.push_back(vector<int>());
            
        levels[level].push_back(root->val);
        
        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
    }
    
    // var
    vector<vector<int>> levels;
};