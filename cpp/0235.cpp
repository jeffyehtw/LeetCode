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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* left;
        TreeNode* right;
        
        if (root == NULL) {
            return NULL;
        } else if ((root == p) || (root == q)) {
            return root;
        }

        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        if ((left == NULL) && (right == NULL)) {
            return NULL;
        } else if (left && right) {
            return root;
        } else {
            return (left == NULL) ? right : left;
        }
    }
};
