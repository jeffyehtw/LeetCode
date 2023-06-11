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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ret = NULL;

        if (root == NULL) {
            ret = new TreeNode(val);
            return ret;
        }

        ret = new TreeNode(root->val);
        if (root->val > val) {
            ret->left = insertIntoBST(root->left, val);
            ret->right = root->right;
        } else {
            ret->left = root->left;
            ret->right = insertIntoBST(root->right, val);
        }

        return ret;
    }
};
