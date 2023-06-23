/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* _p;
    TreeNode* _q;
    unordered_map<TreeNode*, bool> path;
    unordered_map<TreeNode*, TreeNode*> parents;
    void traverse(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return;
        } else if ((_p == NULL) && (_q == NULL)) {
            return;
        }
        if (root == _p) {
            _p = NULL;
        } else if (root == _q) {
            _q = NULL;
        }
        parents[root] = parent;
        traverse(root->left, root);
        traverse(root->right, root);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        _p = p;
        _q = q;
        traverse(root, NULL);

        while (p) {
            path[p] = true;
            p = parents[p];
        }
        while (q) {
            if (path[q]) {
                return q;
            }
            q = parents[q];
        }

        return NULL;
    }
};
