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
    void insert(TreeNode* root, int val) {
        if (root == NULL) {
            return;
        }
        if (val < root->val) {
            if (root->left) {
                insert(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        } else {
            if (root->right) {
                insert(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        insert(root, val);
        return root;
    }
};
