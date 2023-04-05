/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* ret;
    
    if (root == NULL) {
        return root;
    }
    
    ret = malloc(sizeof(struct TreeNode));
    ret->val = root->val;
    ret->left = invertTree(root->right);
    ret->right = invertTree(root->left);
    
    return ret;
}