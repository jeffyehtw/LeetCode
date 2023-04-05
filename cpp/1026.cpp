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
    int ret = INT_MIN;
    int _maxAncestorDiff(TreeNode* root, int min, int max) {
        int left;
        int right;

        if (root == NULL) {
            return -1;
        }

        if (root->val - min > ret) {
            ret = root->val - min;
        }
        if (max > ret + root->val) {
            ret = max - root->val;
        }

        if (root->val < min) {
            min = root->val;
        }
        if (root->val > max) {
            max = root->val;
        }

        left = _maxAncestorDiff(root->left, min, max);
        right = _maxAncestorDiff(root->right, min, max);

        return (left > right) ? left : right;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        _maxAncestorDiff(root, INT_MAX, INT_MIN);
        return ret;
    }
};
