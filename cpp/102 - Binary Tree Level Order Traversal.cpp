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
    // var
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
    
    void traversal(TreeNode* root, int level) {
        if (!root)
            return;
            
        // init
        if (result.empty() || level > result.size() - 1)
            result.push_back(vector<int>());
        
        // add
        result[level].push_back(root->val);
        
        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
    }
};