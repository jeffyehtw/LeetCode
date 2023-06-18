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
    void traverse(TreeNode* root, int _min, int _max) {
        if (root == NULL) {
            return;
        }
        ret = max({
            ret, 
            abs(root->val - _min), 
            abs(root->val - _max)
        });
        _min = min(_min, root->val);
        _max = max(_max, root->val);
        traverse(root->left, _min, _max);
        traverse(root->right, _min, _max);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        traverse(root, root->val, root->val);
        return ret;
    }
};
