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
    unordered_map<int, int> parents;
    void traverse(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return;
        }
        parents[root->val] = parent ? parent->val : -1;
        traverse(root->left, root);
        traverse(root->right, root);
    }
    TreeNode* lca(TreeNode* root, int p, int q) {
        TreeNode* left;
        TreeNode* right;

        if (root == NULL) {
            return NULL;
        } else if ((root->val == p) || (root->val == q)) {
            return root;
        }

        left = lca(root->left, p, q);
        right = lca(root->right, p, q);
        if ((left == NULL) && (right == NULL)) {
            return NULL;
        } else if (left && right) {
            return root;
        } else {
            return (left == NULL) ? right : left;
        }
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        int ret = 0;
        TreeNode* ancestor = NULL;

        traverse(root, NULL);
        ancestor = lca(root, p, q);

        while (p != ancestor->val) {
            p = parents[p];
            ret++;
        }
        while (q != ancestor->val) {
            q = parents[q];
            ret++;
        }

        return ret;
    }
};
