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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
            
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* left, TreeNode* right) {
        if (!left xor !right)
            return false;
        else if (!left && !right)
            return true;
        
        return left->val == right->val && helper(left->right, right->left) && helper(left->left, right->right);
    }
};