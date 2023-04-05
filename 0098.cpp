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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* left, TreeNode* right) {
        if (!root)
            return true;
            
        if (left && root->val <= left->val)
            return false;
        if (right && root->val >= right->val)
            return false;
        
        return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
    }
};