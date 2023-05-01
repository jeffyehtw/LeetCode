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
    TreeNode fake;
    TreeNode* idx = &fake;
    void traversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        traversal(root->left);
        idx->right = new TreeNode(root->val);
        idx = idx->right;
        traversal(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        traversal(root);
        return fake.right;
    }
};
