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
    string tree2str(TreeNode* root) {
        string ret;

        if (root == NULL) {
            return "";
        }

        ret = to_string(root->val);
        if ((root->left == NULL) && (root->right == NULL)) {
            return ret;
        }
        ret += "(" + tree2str(root->left) + ")";
        if (root->right) {
            ret += "(" + tree2str(root->right) + ")";
        }

        return ret;
    }
};
