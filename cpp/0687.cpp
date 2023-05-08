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
    int sub(TreeNode* root, int target) {
        if ((root == NULL) || (root->val != target)) {
            return 0;
        }
        return 1 + max(
            sub(root->left, target), 
            sub(root->right, target)
        );
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;
        int left;
        int right;

        if (root == NULL) {
            return 0;
        }

        ret = max(ret, longestUnivaluePath(root->left));
        ret = max(ret, longestUnivaluePath(root->right));

        left = sub(root->left, root->val);
        right = sub(root->right, root->val);
        ret = max(ret, left + right);

        return ret;
    }
};
