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
private:
    int acc = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* ret = NULL;

        if (root == NULL) {
            return ret;
        }
        ret = new TreeNode(0);
        if (root->right) {
            ret->right = convertBST(root->right);
        }
        acc += root->val;
        ret->val = acc;
        if (root->left) {
            ret->left = convertBST(root->left);
        }

        return ret;
    }
};
