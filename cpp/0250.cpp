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
    int cnt = 0;
    void traverse(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (valid(root, root->val)) {
            cnt++;
        }
        traverse(root->left);
        traverse(root->right);
    }
    bool valid(TreeNode* root, int val) {
        bool ret = true;

        if (root == NULL) {
            return ret;
        } else if (root->val != val) {
            return false;
        }
        ret &= valid(root->left, val);
        ret &= valid(root->right, val);

        return ret;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        traverse(root);
        return cnt;
    }
};
