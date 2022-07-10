/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode* root) {
    int ret = 0;
    
    if (root == NULL) {
        return ret;
    }

    if (root->left) {
        if ((root->left->left == NULL)
            && (root->left->right == NULL)) {
            ret += root->left->val;
        }
        else {
            ret += sumOfLeftLeaves(root->left);
        }
    }
    if (root->right) {
        ret += sumOfLeftLeaves(root->right);
    }
    
    return ret;    
}