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
    int help(TreeNode* root, int index) {
        if (root == NULL) {
            return 0;
        } else if ((root->left == NULL) && (root->right == NULL)) {
            return index;
        }
        
        return max(
            help(root->left, index << 1),
            help(root->right, (index << 1) + 1)
        );
    }
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return help(root, 1);
        }
    }
};
