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
    int ret = 0;
    void traversal(TreeNode* root, int acc) {
        if (root == NULL) {
            return;
        }

        acc = (acc * 10) + root->val;
        if ((root->left == NULL) && (root->right == NULL)) {
            ret += acc;
        }

        traversal(root->left, acc);
        traversal(root->right, acc);
    }
public:
    int sumNumbers(TreeNode* root) {
        traversal(root, 0);
        return ret;
    }
};
