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
    TreeNode* ret;
    int height;
    int h(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return 1 + max(h(root->left), h(root->right));
        }
    }
    void traverse(TreeNode* root, int level) {
        int left = 0;
        int right = 0;

        if (root == NULL) {
            return;
        }

        left = h(root->left);
        right = h(root->right);
        if ((left == right) && (level + left > height)) {
            height = level + left;
            ret = root;
        }
        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        height = -1;
        traverse(root, 0);
        return ret;
    }
};
