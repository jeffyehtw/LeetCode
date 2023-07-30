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
    int smallest(TreeNode* cur) {
        if (cur == NULL) {
            return INT_MIN;
        } else if (cur->left) {
            return smallest(cur->left);
        } else {
            return cur->val;
        }
    }
    int largest(TreeNode* cur) {
        if (cur == NULL) {
            return INT_MAX;
        } else if (cur->right) {
            return largest(cur->right);
        } else {
            return cur->val;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* ret = NULL;

        if (root == NULL) {
            return ret;
        }

        if (root->val == key) {
            if (root->left) {
                ret = new TreeNode(largest(root->left));
            } else if (root->right) {
                ret = new TreeNode(smallest(root->right));
            } else {
                return ret;
            }
            ret->left = deleteNode(root->left, ret->val);
            ret->right = deleteNode(root->right, ret->val);
        } else {
            ret = new TreeNode(root->val);
            ret->left = deleteNode(root->left, key);
            ret->right = deleteNode(root->right, key);
        }

        return ret;
    }
};
