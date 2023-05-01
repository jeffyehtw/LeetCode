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
    int val;
    bool traversal(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        if (root->val != val) {
            return false;
        }
        return traversal(root->left) && traversal(root->right);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        return traversal(root);
    }
};
