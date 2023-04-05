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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int left = 0;
        int right = 0;
        int ret = 0;

        if (root == NULL) {
            return 0;
        }

        left = height(root->left);
        right = height(root->right);

        ret = ((root->left) ? left : 0) + ((root->right) ? right : 0);

        left = diameterOfBinaryTree(root->left);
        right = diameterOfBinaryTree(root->right);

        return max(ret, max(left, right));
    }
};
