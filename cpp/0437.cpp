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
    int ret = 0;
    void traversal(TreeNode* root, long long targetSum) {
        if (root == NULL) {
            return;
        }

        targetSum -= root->val;
        if (targetSum == 0) {
            ret++;
        }

        traversal(root->left, targetSum);
        traversal(root->right, targetSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }

        traversal(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ret;
    }
};
