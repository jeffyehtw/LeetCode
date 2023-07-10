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
    unsigned long long all = 0;
    unsigned long long ret = 0;
    TreeNode* help(TreeNode* root) {
        TreeNode* ret = NULL;

        if (root == NULL) {
            return NULL;
        }
        all += root->val;
        ret = new TreeNode(root->val);
        ret->left = help(root->left);
        ret->right = help(root->right);
        if (ret->left) {
            ret->val += ret->left->val;
        }
        if (ret->right) {
            ret->val += ret->right->val;
        }

        return ret;
    }
    void traverse(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        ret = max(ret, root->val * (all - root->val));
        traverse(root->left);
        traverse(root->right);
    }
public:
    int maxProduct(TreeNode* root) {
        TreeNode* accumulate = help(root);
        traverse(accumulate);
        return ret % 1000000007;
    }
};
