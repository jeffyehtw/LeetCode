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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ret = 0;

        if (root == NULL) {
            return ret;
        }

        if ((root->val >= low) && (root->val <= high)) {
            ret += root->val;
        }
        ret += rangeSumBST(root->left, low, high);
        ret += rangeSumBST(root->right, low, high);

        return ret;
    }
};
