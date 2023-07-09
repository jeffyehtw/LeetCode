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
    void traverse(TreeNode* root, int val, int depth) {
        if (root == NULL) {
            return;
        }
        if (depth == 2) {
            TreeNode* left = new TreeNode(val);
            TreeNode* right = new TreeNode(val);

            left->left = root->left;
            right->right = root->right;
            root->left = left;
            root->right = right;
        } else {
            traverse(root->left, val, depth - 1);
            traverse(root->right, val, depth - 1);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == NULL) {
            return NULL;
        } else if (depth == 1) {
            TreeNode* ret = new TreeNode(val);
            ret->left = root;
            return ret;
        }
        traverse(root, val, depth);
        return root;
    }
};
