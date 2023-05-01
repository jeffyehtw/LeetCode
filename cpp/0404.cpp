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
    bool leaf(TreeNode* root) {
        if (root == NULL) {
            return false;
        } else {
            return (root->left == NULL) && (root->right == NULL);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;

        if (root == NULL) {
            return ret;
        }

        if (root->left && leaf(root->left)) {
            ret += root->left->val;
        } else if (root->left) {
            ret += sumOfLeftLeaves(root->left);
        }
        if (root->right) {
            ret += sumOfLeftLeaves(root->right);
        }
        
        return ret;
    }
};
