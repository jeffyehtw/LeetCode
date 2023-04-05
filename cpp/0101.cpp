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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) {
            return true;
        } else if ((a != NULL && b == NULL) 
            || (a == NULL && b != NULL)) {
            return false;
        }

        return ((a->val == b->val)
            && isSameTree(a->left, b->right)
            && isSameTree(a->right, b->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};
