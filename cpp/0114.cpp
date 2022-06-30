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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        
        if (root->right)
            flatten(root->right);
        
        if (root->left) {
            if (is_leaf(root->left)) {
                root->left->right = root->right;
                root->right = root->left;
                root->left = NULL;
                return;
            }
            
            flatten(root->left);
                
            // var
            TreeNode* it = root->left;
            
            while (it->right)
                it = it->right;
            
            it->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
    
    bool is_leaf(TreeNode* root) {
        return !root->left && !root->right;
    }
};