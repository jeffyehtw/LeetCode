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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool left = true;
        bool right = true;

        if ((root1 == NULL) && (root2 == NULL)) {
            return true;
        } else if ((root1 == NULL) ^ (root2 == NULL)) {
            return false;
        } else if (root1->val != root2->val) {
            return false;
        }

        if (root1->left && root1->right) {
            if ((root2->left == NULL) || (root2->right == NULL)) {
                return false;
            }
            if (root1->left->val != root2->left->val) {
                left = flipEquiv(root1->left, root2->right);
                right = flipEquiv(root1->right, root2->left);
            } else {
                left = flipEquiv(root1->left, root2->left);
                right = flipEquiv(root1->right, root2->right);
            }
        } else if ((root1->left == NULL) && (root1->right == NULL)) {
            return ((root2->left == NULL) && (root2->right == NULL));
        } else {
            if ((root2->left == NULL) ^ (root2->right == NULL)) {
                if ((root1->left == NULL) ^ (root2->left == NULL)) {
                    left = flipEquiv(root1->left, root2->right);
                    right = flipEquiv(root1->right, root2->left);
                } else {
                    left = flipEquiv(root1->left, root2->left);
                    right = flipEquiv(root1->right, root2->right);
                }
            } else {
                return false;
            }
        }

        return (left && right);
    }
};
