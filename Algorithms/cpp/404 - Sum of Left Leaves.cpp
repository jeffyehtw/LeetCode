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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
            
        return helper(root, false);
    }
    
    int helper(TreeNode* root, bool is_left) {
        if (!root->left && !root->right)
            return is_left ? root->val : 0;
    
        // var
        int left = !root->left ? 0 : helper(root->left, true);
        int right = !root->right ? 0 : helper(root->right, false);
    
        return left + right;
    }
};