/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* ret = NULL;

        if (root == NULL) {
            return ret;
        }

        ret = new TreeNode(root->val);

        if (root->right) {
            ret->left = invertTree(root->right);
        }
        if (root->left) {
            ret->right = invertTree(root->left);
        }
        
        return ret;
    }
};
