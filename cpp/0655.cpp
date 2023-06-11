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
    int h;
    vector<vector<string>> ret;
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(
            height(root->left), 
            height(root->right)
        );
    }
    void traversal(TreeNode* root, int r, int c) {
        if (root == NULL) {
            return;
        }
        ret[r][c] = to_string(root->val);
        if (root->left) {
            traversal(root->left, r + 1, c - (1 << (h - r - 1)));
        }
        if (root->right) {
            traversal(root->right, r + 1, c + (1 << (h - r - 1)));
        }
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int m = height(root);
        int n = (1 << m) - 1;
        ret = vector<vector<string>>(m, vector<string>(n, ""));

        h = m - 1;

        traversal(root, 0, (n - 1) / 2);

        return ret;
    }
};
