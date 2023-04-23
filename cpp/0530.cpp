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
    int ret = INT_MAX;
    int _max(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        if (root->right) {
            return _max(root->right);
        } else {
            return root->val;
        }
    }
    int _min(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        if (root->left) {
            return _min(root->left);
        } else {
            return root->val;
        }
    }
    void traversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        if (root->left) {
            traversal(root->left);
            ret = min(ret, root->val - _max(root->left));
        }
        if (root->right) {
            traversal(root->right);
            ret = min(ret, _min(root->right) - root->val);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return ret;
    }
};
