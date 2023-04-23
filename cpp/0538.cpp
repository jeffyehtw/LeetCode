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
    int sum = 0;
    void traversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        if (root->right) {
            traversal(root->right);
        }
        sum += root->val;
        root->val = sum;
        if (root->left) {
            traversal(root->left);
        }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};
