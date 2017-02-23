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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
            
        traversal(root, 1);
        
        return result;
    }
    
    void traversal(TreeNode* root, int level) {
        if (!root->left && !root->right)
            result = min(result, level);
        
        if (root->left)
            traversal(root->left, level + 1);
        if (root->right)
            traversal(root->right, level + 1);
    }
    
    // var
    int result = INT_MAX;
};