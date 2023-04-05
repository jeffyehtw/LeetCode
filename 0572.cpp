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
        if ((a == NULL) && (b == NULL)) {
            return true;
        } else if ((a == NULL) && (b != NULL)
            || (a != NULL) && (b == NULL)) {
            return false;
        }

        return ((a->val == b->val)
            && isSameTree(a->left, b->left)
            && isSameTree(a->right, b->right));
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }

        return (isSameTree(root, subRoot)
            || isSubtree((root) ? root->left : NULL, subRoot)
            || isSubtree((root) ? root->right : NULL, subRoot));
    }
};
