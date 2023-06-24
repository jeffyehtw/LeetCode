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
    unordered_map<TreeNode*, int> umap;
public:
    int rob(TreeNode* root) {
        int exe = 0;
        int pass = 0;
        int ret = 0;

        if (root == NULL) {
            return 0;
        } else if (umap.find(root) != umap.end()) {
            return umap[root];
        }

        exe += root->val;
        if (root->left) {
            exe += rob(root->left->left);
            exe += rob(root->left->right);
        }
        if (root->right) {
            exe += rob(root->right->left);
            exe += rob(root->right->right);
        }

        pass += rob(root->left);
        pass += rob(root->right);

        ret = max(exe, pass);
        umap[root] = ret;

        return ret;
    }
};
